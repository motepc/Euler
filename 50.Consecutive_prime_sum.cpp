/*

The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.
(Not necessarily should start from 2, here 21 terms are 7+9+11+.......)

Which prime, below one-million, can be written as the sum of the most consecutive primes?

*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;



#define MAX 200000
#define U_LIM 1000000


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
				if(out_counter == 0)
					list[out_counter] = j;
				else
					list[out_counter] = list[out_counter-1] + j;

				out_counter++;
				//printf("\n%lld", j);
			}
		}
		//printf("\n");
	}

	return out_counter;
}


int check_prime(int sum)
{
	int i;
	int max_root = 2+(int)sqrt(sum);

	if(sum%2 == 0)
		return 0;

	i = 3;
	while(i < max_root)
	{
		if(sum%i == 0)
			return 0;

		i = i+2;
	}

	return 1;
}


int main()
{
	int i, j, prime[10000], counter, output, len_max = 1;

	prime[0] = 0;
	counter = enlist(&prime[1]);

	for(i=1; i<counter; i++)
	{
		if((prime[i]-prime[i-1]) >= U_LIM)
			break;

		for(j=i-len_max; j>=0; j--)
		{
			if((prime[i]-prime[j]) < U_LIM)
			{
				if(check_prime(prime[i]-prime[j]))
				{
					len_max = i-j;
					output = prime[i]-prime[j];
				}
			}
			else
				break;
		}
	}

	printf("\n\n	%d	%d\n", output, len_max);

	return 0;
}
