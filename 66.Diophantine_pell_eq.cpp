#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



bool is_greater(string x, string max)
{
	int i;

	if(x.size() > max.size())
		return 1;

	if(x.size() < max.size())
		return 0;

	for(i=(x.size()-1); i>=0; i++)
	{
		if(x.at(i) > max.at(i))
			return 1;
		if(x.at(i) < max.at(i))
			return 0;
	}

	return 1;
}


string solve_pell(int period, int iroot, int* states)
{
	int i, min_size, next, mult, carry, counter = 2*period - 2;
	string fract[2];

	next = 49;
	fract[(counter+1)%2].append((char*)(&next), 0, 1);

	next = 48 + states[counter%period];
	fract[counter%2].append((char*)(&next), 0, 1);

	while(counter > 0)
	{
		counter--; carry = 0;

		if(counter == 10001)
			next = iroot;
		else
			next = states[counter%period];

		min_size = fract[0].size()<fract[1].size()?fract[0].size():fract[1].size();

		for(i=0; i<min_size; i++)
		{
			mult = carry + fract[counter%2].at(i) - 48 + next*(fract[(counter+1)%2].at(i) - 48);
			carry = mult/10;
			mult = mult%10 + 48;

			fract[counter%2].replace(i, 1,(char*)(&mult));
		}
		while(i < fract[counter%2].size())
		{
			mult = carry + fract[counter%2].at(i) - 48;
			carry = mult/10;
			mult = mult%10 + 48;

			fract[counter%2].replace(i, 1,(char*)(&mult));

			i++;
		}
		while(i < fract[(counter+1)%2].size())
		{
			mult = carry + next*(fract[(counter+1)%2].at(i) - 48);
			carry = mult/10;
			mult = mult%10 + 48;

			fract[counter%2].append((char*)(&mult), 0, 1);

			i++;
		}
		while(carry > 0)
		{
			mult = carry%10 + 48;
			carry = carry/10;

			fract[counter%2].append((char*)(&mult), 0, 1);
		}

		//cout << "\n	" << fract[counter%2];
		if(counter == 10001)
			break;
		if(counter == 0)
			counter = 10002;
	}

	return fract[1];
}


int main()
{
	int start_timer = clock(), stop_timer;

	string str_x, str_max;
	int N = 1, i, iroot, fract[2], temp, states[220], current, max;
	bool done;

	while(N < 1000)
	{
		N++;
		iroot = (int)sqrt(N);
		current = 0; done = 0;

		if(N == iroot*iroot)
			continue;

		fract[1] = 1;
		fract[0] = iroot;

		//cout << "\n	root(" << N << ") =	[" << iroot << ";(";

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

			states[current-1] = (temp+fract[current%2])/fract[(current+1)%2];
			fract[current%2] = temp;

			if(states[current-1] == 2*iroot)
				done = 1;

			/*cout << states[current-1];
			if(done == 0)
				cout << ",";*/
		}

		//cout << ")], period = " << current;

		if((current%2 == 1)&&(current != 1))
		{
			str_x = solve_pell(current, iroot, &states[0]);
			if(is_greater(str_x, str_max))
			{
				str_max = str_x;
				max = N;
			}

			//cout << "	x = " << str_x;
		}
	}

	cout << "\n\n	Max_D = " << max;

	stop_timer = clock();
	cout << "\n\n	Time taken : " << stop_timer-start_timer << " ms\n\n";

	return 0;
}
