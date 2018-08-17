/*

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order,
but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on.
In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.

*/

#include<iostream>
#include<cstdio>
#include<cmath>


using namespace std;


#define MAX 1000
int prime[7] = {2,3,5,7,11,13,17};



int check(int* num, int length)
{
	int i;
	bool mark[10] = {0};

	for(i=0; i<length; i++)
	{
		if(mark[num[i]] == 0)
			mark[num[i]] = 1;
		else
			return 0;
	}

	return 1;
}


long long add(int* num, int length, long long* output)
{
	int i, j, sub = 0;
	long long temp;

	for(i=0; i<2; i++)
	{
		sub += num[length -2 +i];
		sub = sub*10;
	}

	i = 0;
	while(i < 10)
	{
		temp = sub + i;

		if(temp%prime[length-3] == 0)
		{
			num[length] = i;
			if(check(&num[0], length+1))
			{
				if(length == 9)
				{
					temp = 0;

					printf("\n	");
					for(j=0; j<10; j++)
					{
						printf("%d", num[j]);

						temp = temp*10;
						temp += num[j];
					}

					*output += temp;
					printf("	%lld	%lld", temp, *output);
				}
				else
					add(&num[0], length+1, output);
			}
		}

		i++;
	}

	return *output;
}


int main()
{
	int temp, i, num[10] = {0}, mult = 100;
	long long output = 0;

	while(mult < MAX)
	{
		temp = mult;
		for(i=0; i<3; i++)
		{
			num[2-i] = temp%10;
			temp = temp/10;
		}

		if(check(&num[0], 3))
		{
			output = add(&num[0], 3, &output);
		}

		mult++;
	}

	printf("\n\n	Output = %lld\n", output);

	return 0;
}
