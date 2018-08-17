/*

The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?

*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;



#define MAX 200000
#define TARGET 4


int enlist(int* list)
{
	int freq, counter, current, done, out_counter = 0;
	long long input[11][2], i, j, max_root = 0, start, stop, prime_no[10000];
	bool prime_bool[MAX];


	/*	Input process	*/
	//scanf ("%d\n", &freq);
	freq = 1;

	/*for(i=0; i<freq; i++)
	{
		std::cin >> input[i][0] >> input[i][1];
	}*/
	input[0][0] = 1;
	input[0][1] = 100000;

	for(i=0; i<freq; i++)
		if(max_root < input[i][1])
			max_root = input[i][1];

	max_root = 2 + (int)sqrt(max_root);

	/*	Reset grid	*/
	for(i=0; i<MAX; i++)
		prime_bool[i] = 0;


	/*	Calculate array of prime number less than sqrt(max input)	*/
	prime_no[0] = 2; counter = 1;
	current = 0; start = 3;
	while(start < max_root)
	{
		j = 2;
		while(j*prime_no[current] < 2*max_root)		// Mark all composite numbers
		{
			prime_bool[j*prime_no[current]] = 1;
			j++;
		}

		stop = (prime_no[current]*prime_no[current])<max_root ? (prime_no[current]*prime_no[current]):max_root;
		for(j=start; j<stop; j++)
		{
			if(prime_bool[j] == 0)
			{
				prime_no[counter] = j;
				counter++;
			}
		}
		start = stop;
		current++;
	}

	/*	For just next 1 prime number greater than or equal to sqrt(max input)	*/
	done = 0;
	stop = (prime_no[current-1]*prime_no[current-1])<(2*max_root) ? (prime_no[current-1]*prime_no[current-1]):(2*max_root);
	for(j=start; j<stop; j++)
	{
		if(prime_bool[j] == 0)
		{
			prime_no[counter] = j;
			counter++;
			done = 1;
		}
	}
	start = stop;

	if(done == 0)
	{
		j = 2;
		while(j*prime_no[current] < 2*max_root)
		{
			prime_bool[j*prime_no[current]] = 1;
			j++;
		}

		j = counter;
		while(j==counter)
		{
			if(prime_bool[start] == 0)
			{
				prime_no[counter] = start;
				counter++;
			}
			start++;
		}
	}


	/*	Calculate prime number between m and n	*/
	for(i=0; i<freq; i++)
	{
		for(j=0; j<MAX; j++)
			prime_bool[j] = 0;

		if(input[i][0] == 1)
			prime_bool[0] = 1;

		current = 0; done = 0;
		max_root = 2+(int)sqrt(input[i][1]);

		while((done == 0) && (current<counter))
		{
			if(prime_no[current] >= max_root)
				done++;

			j = (int)((input[i][0]-1)/prime_no[current]);
			if(j<2)
				j = 2;
			while(j*prime_no[current] < input[i][0])
			{
				j++;
			}
			while(j*prime_no[current] < (input[i][1]+1))
			{
				prime_bool[j*prime_no[current]-input[i][0]] = 1;
				j++;
			}
			current++;
		}

		for(j=input[i][0]; j<(input[i][1]+1); j++)
		{
			if(prime_bool[j-input[i][0]] == 0)
			{
				list[out_counter] = j;
				out_counter++;
				//printf("\n%lld", j);
			}
		}
		//printf("\n");
	}

	return out_counter;
}


int mark_fact(int num, int counter, int* prime, int* factors)
{
	int cur_prime = 0, cur_fact = 0;

	while(num > 1)
	{
		if(num%prime[cur_prime] == 0)
		{
			if((factors[cur_fact] != 0)&&(factors[cur_fact] != prime[cur_prime]))
				cur_fact += 2;

			if(cur_fact == 2*TARGET)
				return 0;

			factors[cur_fact] = prime[cur_prime];
			factors[cur_fact+1]++;

			num = num/prime[cur_prime];
		}
		else
		{
			cur_prime++;
			if(cur_prime == counter)
				return 0;
		}
	}

	if(cur_fact == (2*TARGET - 2))
		return 1;
	else
		return 0;
}


int check_match(int* i, int* j)
{
	int x;

	for(x=0; x<TARGET; x++)
		if(i[2*x] == j[2*x])
			if(i[2*x+1] == j[2*x+1])
				return 0;

	return 1;
}


int main()
{
	int i, j, prime[10000], counter, output, num, done;
	int factors[TARGET][2*TARGET];

	counter = enlist(&prime[0]);

	num = 2;
	while(1)
	{
		for(i=0; i<TARGET; i++)
			for(j=0; j<2*TARGET; j++)
				factors[i][j] = 0;

		done = 1;
		for(i=0; (i<TARGET)&&(done == 1); i++)
			done = done*mark_fact(num+i, counter, &prime[0], &factors[i][0]);

		if(done == 1)
		{
			for(i=0; (i<TARGET)&&(done == 1); i++)
				for(j=i+1; (j<TARGET)&&(done == 1); j++)
					done = done*check_match(&factors[i][0], &factors[j][0]);
		}

		if(done == 1)
		{
			printf("\n\n	%d\n", num);
			return 0;
		}

		num++;
	}
}
