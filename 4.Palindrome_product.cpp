/*

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.


Commented code gives only solution for above problem statement.
Current code gives list.
*/

#include<iostream>
#include<cstdio>
#include<math.h>

using namespace std;


int check_palin(int palin)
{
	int invert = 0, input = palin;

	while(input > 0)
	{
		invert = invert*10;
		invert = invert + input%10;
		input = input/10;
	}

	if(invert == palin)
		return 1;
	else
		return 0;
}


int main()
{
	int max = 999, cut = 0, part, found;

	while(cut<200)//while(1)
	{
		part = cut/2 + cut%2;

		while(part<=cut)
		{
			found = check_palin((max-part)*(max-cut+part));

			if(found == 1)
			{
				//printf("\n\n	%d * %d = %d\n", (max-part), (max-cut+part), (max-part)*(max-cut+part));
				printf("	%d * %d = %d\n", (max-part), (max-cut+part), (max-part)*(max-cut+part));

				//return 0;
			}

			part++;
		}

		cut++;
	}

	return 0;
}
