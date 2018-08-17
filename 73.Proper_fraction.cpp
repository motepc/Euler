#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



// Farey sequence is good and quick way.


int gcd(int i, int j)
{
	if(j%i == 0)
		return i;

	return gcd(j%i, i);
}


int main()
{
	int start_timer = clock(), stop_timer;

	int i, j, num, den0, den1, d = 12000;
	unsigned long long counter = 0;

	num = 1; den0 = 3; den1 = 2;

	j = 2;
	while(j <= d)
	{
		i = (int)((float)j*num/den0);

		while(den0*i <= num*j)
			i++;

		while(den1*i < num*j)
		{
			if(gcd(i,j) == 1)
				counter++;

			i++;
		}

		j++;
	}

	cout << "\n\n	" << counter << "\n\n";

	stop_timer = clock();
	cout << "Time taken : " << stop_timer-start_timer << " ms\n";

	return 0;
}
