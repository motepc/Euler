#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



static int loop[7] = {169, 871, 872, 1454, 45361, 45362, 363601};
static int repeat[8] = {3,2,2,3,2,2,3,1};


int check_loop(int next)
{
	int i;

	for(i=0; i<7; i++)
		if(loop[i] == next)
			break;

	return repeat[i];
}


int main()
{
	int start_timer = clock(), stop_timer;

	int i, fact[10], next, temp, current, period[50000], found, counter = 0;

	fact[0] = 1;
	for(i=1; i<10; i++)
		fact[i] = i*fact[i-1];


	for(i=1; i<50000; i++)
	{
		next = i;

		found = check_loop(next);
		period[i] = found;

		while(found == 1)
		{
			current = next; temp = next; next = 0;
			while(temp>0)
			{
				next += fact[temp%10];
				temp /= 10;
			}

			if(current == next)
				found = 0;
			else if(next < i)
			{
				found = 0;
				period[i] += period[next];
			}
			else
				found = check_loop(next);

			period[i] += found;
		}

		if(period[i] == 60)
			counter++;
	}

	for(i=50000; i<1000000; i++)
	{
		next = i;

		if(next == 363601)
			found = 3;
		else
			found = 1;

		period[0] = found;

		while(found == 1)
		{
			current = next; temp = next; next = 0;
			while(temp>0)
			{
				next += fact[temp%10];
				temp /= 10;
			}

			if(current == next)
				found = 0;
			else if(next < 50000)
			{
				found = 0;
				period[0] += period[next];
			}
			else if(next == 363601)
				found = 3;

			period[0] += found;
		}

		if(period[0] == 60)
			counter++;
	}

	cout << "\n\n	Counter = " << counter;

	stop_timer = clock();
	cout << "\n\nTime taken : " << stop_timer-start_timer << " ms\n";

	return 0;
}
