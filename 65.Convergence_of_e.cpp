#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



int main()
{
	int start_timer = clock(), stop_timer;

	int i, min_size, next, mult, carry, counter = 100;
	string fract[2];

	next = 49;
	fract[0].append((char*)(&next), 0, 1);
	fract[1].append((char*)(&next), 0, 1);

	while(counter > 1)
	{
		counter--; carry = 0;

		if(counter%3 == 0)
			next = 2*counter/3;
		else if(counter == 1)
			next = 2;
		else
			next = 1;

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
	}

	next = 0;
	for(i=0; i<fract[1].size(); i++)
		next += fract[1].at(i) - 48;

	cout << "\n\n	Sum = " << next;

	stop_timer = clock();
	cout << "\n\n	Time taken : " << stop_timer-start_timer << " ms\n\n";

	return 0;
}
