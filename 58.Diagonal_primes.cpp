#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;


#define MAX 200000



int mark_prime(int* arr_prime)
{
	int freq, counter, current, done, output = 0;
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
				arr_prime[output++] = j;
		}
	}

	return output;
}


int main()
{
	int i, j, length, diag, prime, total, squarert, add, counter, arr_prime[9600];

	counter = mark_prime(&arr_prime[0]);

	length = 2; diag = 1;
	prime = 0; total = 1;
	while(1)
	{
		total += 4;

		for(i=0; i<4; i++)
		{
			diag += length;

			squarert = ((int)sqrt(diag)) +2;
			add = 1;

			for(j=0; arr_prime[j]<squarert; j++)
				if(diag%arr_prime[j] == 0)
				{
					add = 0;
					break;
				}

			prime += add;
		}

		//printf("\n	prime = %d	total = %d	percent = %d	last=%d", prime, total, 100*prime/total, diag);
		if(10*prime < total)
			break;

		length += 2;
	}

	printf("\n\n	Length = %d\n", length+1);

	return 0;

}
