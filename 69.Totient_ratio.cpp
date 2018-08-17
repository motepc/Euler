#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



#define MAX 200000


void mark_prime(string* prime_str)
{
	int freq, counter, current, done, unity = 49, zero = 48;
	long long input[11][2], i, j, max_root = 0, start, stop, prime_no[10000];
	bool prime_bool[MAX];


	/*	Input process	*/
	/*scanf ("%d\n", &freq);

	for(i=0; i<freq; i++)
	{
		std::cin >> input[i][0] >> input[i][1];
	}*/

	freq = 1;
	input[0][0] = 1; input[0][1] = 100000;

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
				(*prime_str).append((char*)(&unity), 0, 1);
			else
				(*prime_str).append((char*)(&zero), 0, 1);
		}
	}

	return;
}


int main()
{
	int start_timer = clock(), stop_timer;

	int N = 1, i, temp, counter, max[2] = {1,1};
	string prime_str;

	mark_prime(&prime_str);

	i = 1;
	while(1)
	{
		i++;
		if(prime_str.at(i-1) == 49)
		{
			if(N*i < 1000001)
				N = N*i;
			else
				break;
		}
	}

	cout << "\n\n	" << N;

	stop_timer = clock();
	cout << "\n\n	Time taken : " << stop_timer-start_timer << " ms\n\n";

	return 0;
}
