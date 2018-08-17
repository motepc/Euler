/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16,
the smallest number that can be written as the sum of two abundant numbers is 24.
By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number
that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include <fstream>

using namespace std;



#define MAX 28124
#define ABUND_MAX 7000

int main()
{
	int i, j, sum, abun[ABUND_MAX], counter;
	bool check[MAX];
	long long output;

	for(i=0; i<MAX; i++)
		check[i] = 0;

	counter = 0;
	for(i=2; i<MAX; i++)
	{
		j = 1; sum = 0;
		while(j <= ((int)sqrt(i)))
		{
			if(i%j == 0)
			{
				sum = sum + j;
				sum = sum + i/j;
			}
			j++;
		}
		sum = sum - i;
		if(((int)sqrt(i))*((int)sqrt(i)) == i)
			sum = sum - ((int)sqrt(i));

		if(sum > i)
		{
			abun[counter++] = i;
		}
	}

	for(i=0; i<counter; i++)
		for(j=0; j<counter; j++)
			if((abun[i]+abun[j]) < MAX)
				check[abun[i]+abun[j]] = 1;

	output = 0;
	for(i=1; i<MAX; i++)
		if(check[i] == 0)
			output = output + i;

	cout << "\n	" << output << "\n";

	return 0;
}
