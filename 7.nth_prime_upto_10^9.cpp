/*
Code gives nth prime number. Prime number should be less than 10^9.
n should be entered manually on line 14 as ASKED.
*/

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;



#define ASKED 10001
#define MAX 200000


int prime_count(int glo_counter, long long begin, long long end)
{
	int freq, counter, current, done;
	long long input[11][2], i, j, max_root = 0, start, stop, prime_no[10000];
	bool prime_bool[MAX];


	/*	Input process	*/
	//scanf ("%d\n", &freq);
	freq = 1;

	/*for(i=0; i<freq; i++)
	{
		std::cin >> input[i][0] >> input[i][1];
	}*/
	input[0][0] = begin;
	input[0][1] = end;

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
				//printf("\n%lld", j);
				glo_counter++;
				if(glo_counter == ASKED)
					printf("\n\n%lld\n", j);
			}
		}
		//printf("\n");
	}

	return glo_counter;
}

int main()
{
	int glo_counter = 0, i = 0;

	while(glo_counter < ASKED)
	{
		glo_counter = prime_count(glo_counter, 100000*i+1, 100000*(i+1));
		i++;
	}

	return 0;
}
