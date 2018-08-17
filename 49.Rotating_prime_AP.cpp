/*

The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways:
(i) each of the three terms are prime, and,
(ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property,
but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?

*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;



#define MAX 200000


int prime_mark(int* prime)
{
	int freq, counter, current, done;
	long long input[11][2], i, j, max_root = 0, start, stop, prime_no[10000];
	bool prime_bool[MAX];
	int prime_counter = 0;


	/*	Input process	*/
	//scanf ("%d\n", &freq);
	freq = 1;

	/*for(i=0; i<freq; i++)
	{
		std::cin >> input[i][0] >> input[i][1];
	}*/
	input[0][0] = 1000;
	input[0][1] = 9999;

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
				prime[prime_counter] = j;
				prime_counter++;
			}
		}
		//printf("\n");
	}

	return prime_counter;
}


int check_rot(int i, int j, int k)
{
	int digit[3][10] = {0};
	int x, y;

	for(x=0; x<4; x++)
	{
		digit[0][i%10]++;
		i = i/10;
	}

	for(x=0; x<4; x++)
	{
		digit[1][j%10]++;

		j = j/10;
	}
	for(x=0; x<10; x++)
		if(digit[0][x] != digit[1][x])
			return 0;

	for(x=0; x<4; x++)
	{
		digit[2][k%10]++;

		k = k/10;
	}
	for(x=0; x<10; x++)
		if(digit[0][x] != digit[2][x])
			return 0;

	return 1;
}


int main()
{
	int prime[1100], total, diff, next, i, j, k;

	total = prime_mark(&prime[0]);

	i = 0;
	while(i < total)
	{
		j = i+1;
		while(j < total)
		{
			diff = prime[j] - prime[i];
			next = prime[j] + diff;

			k = j+1;
			while(k < total)
			{
				if(next == prime[k])
				{
					if(check_rot(prime[i], prime[j], prime[k]))
					{
						printf("\n\n	%d = %d	%d = %d	%d = %d", i, prime[i], j, prime[j], k, prime[k]);

						//return 0;
					}
				}

				k++;
			}

			j++;
		}

		i++;
	}

	return 0;
}
