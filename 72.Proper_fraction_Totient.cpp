#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



int main()
{
	int start_timer = clock(), stop_timer;

	int i, j, d = 1000001;
	int* phi = new int [d];
	unsigned long long counter = 0;

	for(i=0; i<d; i++)
		phi[i] = i;

	for(i=2; i<d; i++)
	{
		if(phi[i] != i)
			continue;

		for(j=i; j<d; j+=i)
		{
			phi[j] = phi[j]/i;
			phi[j] = phi[j]*(i-1);
		}
	}

	for(i=2; i<d; i++)
	{
		counter += phi[i];
	}

	cout << "\n\n	" << counter << "\n\n";

	stop_timer = clock();
	cout << "Time taken : " << stop_timer-start_timer << " ms\n";

	return 0;
}
