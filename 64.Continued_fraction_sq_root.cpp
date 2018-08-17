#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



int main()
{
	int start_timer = clock(), stop_timer;

	int N = 1, i, iroot, fract[2], temp, states[2][3], current, counter = 0;
	bool done;

	while(N < 10000)
	{
		N++;
		iroot = (int)sqrt(N);
		current = 0; done = 0;

		if(N == iroot*iroot)
			continue;

		fract[1] = 1;
		fract[0] = iroot;


		// First iteration
		current++;
		temp = fract[current%2];
		fract[current%2] = fract[(current+1)%2];	// Num
		fract[(current+1)%2] = N - fract[(current+1)%2]*fract[(current+1)%2];	// Den

		if(fract[(current+1)%2]%temp != 0)
		{
			cout << "\n\n	Faulty algo\n\n";
			return 0;
		}
		fract[(current+1)%2] = fract[(current+1)%2]/temp;

		temp = iroot;
		while((temp+fract[current%2])%fract[(current+1)%2] != 0)
			temp--;

		states[0][0] = (temp+fract[current%2])/fract[(current+1)%2];
		fract[current%2] = temp;
		states[0][1] = fract[current%2];
		states[0][2] = fract[(current+1)%2];
		//cout << "\n	root(" << N << ") =	[" << iroot << ";(" << states[0][0];


		// Next iterations
		while(done == 0)
		{
			current++;
			temp = fract[current%2];
			fract[current%2] = fract[(current+1)%2];	// Num
			fract[(current+1)%2] = N - fract[(current+1)%2]*fract[(current+1)%2];	// Den

			if(fract[(current+1)%2]%temp != 0)
			{
				cout << "\n\n	Faulty algo\n\n";
				return 0;
			}
			fract[(current+1)%2] = fract[(current+1)%2]/temp;

			temp = iroot;
			while((temp+fract[current%2])%fract[(current+1)%2] != 0)
				temp--;

			states[1][0] = (temp+fract[current%2])/fract[(current+1)%2];
			fract[current%2] = temp;
			states[1][1] = fract[current%2];
			states[1][2] = fract[(current+1)%2];

			done = 1;
			for(i=0; i<3; i++)
				if(states[0][i] != states[1][i])
					done = 0;

			/*if(done == 0)
				cout << "," << states[1][0];
			else
				cout << ")], period = " << current-1;*/
		}

		if(current%2 == 0)
			counter++;
	}

	cout << "\n\n	Counter = " << counter;

	stop_timer = clock();
	cout << "\n\n	Time taken : " << stop_timer-start_timer << " ms\n\n";

	return 0;
}
