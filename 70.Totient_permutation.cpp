#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



#define EULER


bool is_match(int N, int phi)
{
	int i, j, digits[2][10];

	for(i=0; i<2; i++)
		for(j=0; j<10; j++)
			digits[i][j] = 0;

	j = N;
	while(j > 0)
	{
		digits[0][j%10]++;
		j = j/10;
	}

	j = phi;
	while(j > 0)
	{
		digits[1][j%10]++;
		j = j/10;
	}

	for(i=0; i<10; i++)
		if(digits[0][i] != digits[1][i])
			return 0;

	return 1;
}


int main()
{
#ifdef EULER
	int start_timer = clock(), stop_timer;
#endif

	int freq, t, i, j, N;
	unsigned long long min[2];


#ifdef EULER
	freq = 1;
#else
	scanf ("%d\n", &freq);
#endif

	for(t=0; t<freq; t++)
	{
#ifdef EULER
		N = 10000000;
#else
		cin >> N;
#endif

		int* phi = new int [N];

		for(i=0; i<N; i++)
			phi[i] = i;

		for(i=2; i<N; i++)
		{
			if(phi[i] != i)
				continue;

			for(j=i; j<N; j+=i)
			{
				phi[j] = phi[j]/i;
				phi[j] = phi[j]*(i-1);
			}
		}

		if(N < 22)
			cout << "No solution.";
		else
		{
			min[0] = 21ULL; min[1] = 12ULL;
			for(i=21; i<N; i++)
				if(min[1]*i <= min[0]*phi[i])
					if(is_match(i, phi[i]))
					{
						min[0] = (unsigned long long)i;
						min[1] = (unsigned long long)phi[i];
					}

			cout << min[0];
		}

		cout << "\n";
		delete[] phi;
	}

#ifdef EULER
	stop_timer = clock();
	cout << "Time taken : " << stop_timer-start_timer << " ms\n";
#endif

	return 0;
}
