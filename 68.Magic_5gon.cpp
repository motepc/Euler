#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



void check_max(int* loc, int* output)
{
	int i, order[15], imin = 5;
	bool greater = 0;

	for(i=6; i<10; i++)
		if(loc[i] < loc[imin])
			imin = i;

	for(i=0; i<5; i++)
	{
		order[3*i+0] = loc[(imin+i)%5 + 5];
		order[3*i+1] = loc[(imin+i)%5];
		order[3*i+2] = loc[((imin+i)%5+1)%5];
	}

	for(i=0; i<15; i++)
	{
		if(order[i] < output[i])
		{
			greater = 0;
			break;
		}
		if(order[i] > output[i])
		{
			greater = 1;
			break;
		}
	}

	if(greater)
		for(i=0; i<15; i++)
			output[i] = order[i];

	return;
}


void permutations(int* loc, int* output, int current, int sum)
{
	int i, j;

	if(current == 10)
	{
		check_max(&loc[0], &output[0]);

		return;
	}

	if(current > 4)
		for(i=1; i<11; i++)
		{
			for(j=0; j<current; j++)
				if(loc[j] == i)
					break;

			if(j == current)
			{
				loc[current] = i;

				if(current == 5)
					sum = loc[0] + loc[1] + loc[5];

				if(sum == (loc[current-5] + loc[(current-4)%5] + loc[current]))
					permutations(&loc[0], &output[0], current+1, sum);
			}
		}
	else
		for(i=1; i<10; i++)
		{
			for(j=0; j<current; j++)
				if(loc[j] == i)
					break;

			if(j == current)
			{
				loc[current] = i;

				permutations(&loc[0], &output[0], current+1, 0);
			}
		}

	return;
}


int main()
{
	int start_timer = clock(), stop_timer;

	int i, loc[10], output[15];

	for(i=0; i<15; i++)
		output[i] = 0;

	permutations(&loc[0], &output[0], 0, 0);

	cout << "\n\n";
	for(i=0; i<15; i++)
	{
		if(i%3 == 0)
			cout << "	";

		cout << output[i];
	}

	stop_timer = clock();
	cout << "\n\n	Time taken : " << stop_timer-start_timer << " ms\n\n";

	return 0;
}
