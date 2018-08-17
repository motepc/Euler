#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



int main()
{
	int start_timer = clock(), stop_timer;

	int i, j, num, den, d = 1000000;

	num = 3; den = 8;

	j = 2;
	while(j <= d)
	{
		i = (int)((float)j*3/7);
		while(7*i < 3*j)
		{
			if(i*den > num*j)	// Should add 1 more condition gcd(i,j) == 1
			{
				num = i;
				den = j;
			}

			i++;
		}

		j++;
	}

	cout << "\n\n	" << num << "/" << den << "\n\n";

	stop_timer = clock();
	cout << "Time taken : " << stop_timer-start_timer << " ms\n";

	return 0;
}
