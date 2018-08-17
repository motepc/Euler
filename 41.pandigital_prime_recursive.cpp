/*

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?


Note - One should never check for 9-digit pandigital and 8-digit pandigital numbers.
Because sum of all digits in those number is divisible by 3, hence none of them are prime.

*/
#include<iostream>
#include<cstdio>
#include<cmath>


using namespace std;



int check_prime(int* num, int pan)
{
	int i, max;
	long long val = 0;

	if((num[pan-1]%2) == 0)
		return 0;

	for(i=0; i<pan; i++)
	{
		val = val*10;
		val += num[i];
	}

	max = 1 + (int)(sqrt(val) + 0.5);

	i = 3;
	while(i < max)
	{
		if(val%i == 0)
		{
			//printf("	Check	%lld for %d\n", val, i);
			return 0;
		}

		i += 2;
	}

	return 1;
}


int add_digit(int* num, int length, int pan)
{
	int j, i = pan, done = 0;

	if(length == pan)
	{
		if(check_prime(&num[0], pan))
		{
			printf("\n\n	");
			for(j=0; j<pan; j++)
				printf("%d", num[j]);

			printf("\n");
			return 1;
		}

		return 0;
	}

	while((i > 0)&&(done == 0))
	{
		for(j=0; j<length; j++)
			if(num[j] == i)
				break;

		if(j == length)
		{
			num[length] = i;
			done = add_digit(&num[0], length+1, pan);
		}

		i--;
	}

	return done;
}


int main()
{
	int num[9], i = 7, done = 0;

	while(done == 0)
	{
		done = add_digit(&num[0], 0, i);
		i--;
	}

	return 0;
}
