#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;



bool check_digit(int num, bool* digit)
{
	int i;
	bool new_digit[10] = {0}, match = 1;

	while(num > 0)
	{
		new_digit[num%10] = 1;
		num = num/10;
	}

	for(i=0; i<10; i++)
		if(digit[i] != new_digit[i])
			match = 0;

	return match;
}


int main()
{
	int num, mult, i, temp;
	bool digit[10], next;

	num = 1;
	while(1)
	{
		for(i=0; i<10; i++)
			digit[i] = 0;

		temp = num;
		while(temp > 0)
		{
			digit[temp%10] = 1;
			temp = temp/10;
		}

		next = 1; mult = 2;
		while(next == 1)
		{
			next = check_digit(num*mult, &digit[0]);
			mult++;

			if((mult == 7)&&(next == 1))
			{
				printf("\n\n	%d\n", num);
				return 0;
			}
		}

		num++;
	}
}
