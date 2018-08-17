#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



int main()
{
	int start_timer = clock(), stop_timer;

	string powers[10];
	int i, j, temp, carry, n, counter = 9, start = 2;

	n = 48;
	for(i=0; i<10; i++)
	{
		powers[i].append((char*)(&n), 0, 1);
		n++;
	}

	n = 2;
	while(start < 10)
	{
		for(i=start; i<10; i++)
		{
			j=0; carry = 0;
			while(j < powers[i].size())
			{
				temp = carry + (powers[i].at(j)-48)*i;
				carry = temp/10;
				temp = temp%10 + 48;

				powers[i].replace(j, 1,(char*)(&temp));

				j++;
			}
			while(carry > 0)
			{
				temp = carry%10 + 48;
				carry = carry/10;

				powers[i].append((char*)(&temp), 0, 1);
			}

			if(powers[i].size() == n)
				counter++;
			if(powers[i].size() < n)
				start = i+1;
		}

		n++;
	}

	cout << "\n\n	Counter = " << counter;

	stop_timer = clock();
	cout << "\n\n	Time taken : " << stop_timer-start_timer << " ms\n\n";

	return 0;

}
