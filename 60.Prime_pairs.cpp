#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;


#define MAX 200000
#define LIMIT 1500
#define GR_SZ 5



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

			//if(output == (LIMIT+1))
				//printf("\n\n	%d\n\n", arr_prime[LIMIT]);
		}
	}

	return output;
}


bool check_prime(int num, int* arr_prime)
{
	int squarert, j;

	squarert = ((int)sqrt(num)) + 2;

	for(j=0; arr_prime[j]<squarert; j++)
		if(num%arr_prime[j] == 0)
			return 0;

	return 1;
}


bool join(int a, int b, int* arr_prime)
{
	int temp, a1;

	temp = b; a1 = a;
	while(temp > 0)
	{
		a1 = a1*10;
		temp = temp/10;
	}
	a1 += b;

	if(check_prime(a1, arr_prime))
	{
		temp = a;
		while(temp > 0)
		{
			b = b*10;
			temp = temp/10;
		}
		b += a;

		return check_prime(b, arr_prime);
	}
	else
		return 0;
}


bool concatenate(int current, int pos, int* group, int* arr_prime)
{
	bool done;
	int i;

	if(current == 0)
		return 1;

	for(i=0; i<current; i++)
	{
		done = join(arr_prime[group[i]], arr_prime[pos], arr_prime);

		if(done == 0)
			return 0;
	}

	return 1;
}


bool combinations(int* group, int* arr_prime, int current, int* min)
{
	bool done = 0;
	int pos, next, j;

	if(current == GR_SZ)
	{
		j = 0;
		//printf("\n\n	Found");
		for(pos=0; pos<GR_SZ; pos++)
		{
			j += arr_prime[group[pos]];
			//printf("	%d", arr_prime[group[pos]]);
		}

		if(j < *min)
			*min = j;

		//printf("\n\n	Total = %d	Min = %d\n\n", j, *min);
		return 1;
	}

	if(current == 0)
		next = 2;
	else
		next = group[current-1] + 1;

	for(pos=next; pos<LIMIT; pos++)
	{
		if(concatenate(current, pos, group, arr_prime))
		{
			group[current] = pos;
			done = combinations(group, arr_prime, current+1, min);
		}

		if(done)
			return 1;
	}

	return done;
}


int main()
{
	int i, j, counter, arr_prime[9600], group[5], min = 100000;

	counter = mark_prime(&arr_prime[0]);
	arr_prime[2] = 3;

	combinations(&group[0], &arr_prime[0], 0, &min);

	printf("\n\n	Min = %d\n\n", min);

	return 0;

}
