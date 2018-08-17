#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;



void convert_str(int a, string* power)
{
	int digit;

	(*power).clear();
	while(a > 0)
	{
		digit = a%10 + 48;
		a = a/10;

		(*power).append((char*)(&digit), 0, 1);
	}
}


int mult(int a, string* power)
{
	int i, size, ans, sum = 0, carry = 0;

	size = (*power).size();
	for(i=0; i<size; i++)
	{
		ans = carry + a*((*power).at(i) - 48);

		carry = ans/10;
		ans = ans%10 + 48;

		sum += ans - 48;
		(*power).replace(i, 1,(char*)(&ans));
	}

	while(carry > 0)
	{
		ans = carry%10 + 48;
		carry = carry/10;

		sum += ans - 48;
		(*power).append((char*)(&ans), 0, 1);
	}

	return sum;
}


int main()
{
	int a, b, sum, max = 0;
	string power;

	for(a=2; a<100; a++)
	{
		convert_str(a, &power);

		for(b=2; b<100; b++)
		{
			sum = mult(a, &power);

			if(sum > max)
				max = sum;
		}
	}

	printf("\n\n	%d\n", max);

	return 0;

}
