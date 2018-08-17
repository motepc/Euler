/*

The series, 11 + 22 + 33 + ... + 1010 = 10405071317.

Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.

*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;



int main()
{
	int i, j, k, carry, num[10], acc[10] = {0};

	for(i=1; i<1001; i++)
	{
		num[0] = 1;
		for(j=1; j<10; j++)
			num[j] = 0;

		for(j=0; j<i; j++)
		{
			carry = 0;
			for(k=0; k<10; k++)
			{
				carry += num[k]*i;
				num[k] = carry%10;
				carry = carry/10;
			}
		}

		carry = 0;
		for(j=0; j<10; j++)
		{
			carry += num[j] + acc[j];
			acc[j] = carry%10;
			carry = carry/10;
		}
	}

	printf("\n\n	");
	for(j=0; j<10; j++)
		printf("%d", acc[9-j]);
	printf("\n");

	return 0;
}
