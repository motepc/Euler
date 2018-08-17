#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;



void convert_str(int num, string* op1)
{
	int digit;

	(*op1).clear();
	while(num > 0)
	{
		digit = num%10 + 48;
		num = num/10;

		(*op1).append((char*)(&digit), 0, 1);
	}
}


void add_str(string* op1, string* op2)
{
	int i, size, ans, carry = 0;

	size = (*op1).size();
	(*op2).clear();

	for(i=0; i<size; i++)
	{
		ans = carry + (*op1).at(i) + (*op1).at(size -i -1) - 96;
		carry = ans/10;
		ans = ans%10 + 48;

		(*op2).append((char*)(&ans), 0, 1);
	}
	if(carry > 0)
	{
		carry += 48;
		(*op2).append((char*)(&carry), 0, 1);
	}
}


bool palin_check(string* op3)
{
	int i, half, max;

	half = (*op3).size()/2;
	max = (*op3).size() - 1;

	for(i=0; i<half; i++)
		if(((*op3).at(i)) != ((*op3).at(max - i)))
			return 0;

	return 1;
}


int main()
{
	string operand[2];
	int num, counter, output = 0;

	for(num=1; num<10000; num++)
	{
		convert_str(num, &operand[0]);

		counter = 0;
		while(counter < 50)
		{
			add_str(&operand[counter%2], &operand[(counter+1)%2]);

			if(palin_check(&operand[(counter+1)%2]))
				break;

			counter++;
		}

		if(counter == 50)
			output++;
	}

	printf("\n\n	%d\n", output);

	return 0;

}
