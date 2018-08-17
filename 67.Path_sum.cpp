#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include <fstream>


using namespace std;



int main()
{
	int start_timer = clock(), stop_timer;

	int i, row, input, prev, accum[2][100];

	ifstream infile;
	infile.open("p067_triangle.txt");

	infile >> input;
	accum[1][0] = input;
	for(row=2; row<101; row++)
	{
		for(i=0; i<row; i++)
		{
			infile >> input;

			// Add higher value from prev row
			if(i == 0)
				prev = accum[(row+1)%2][0];
			else if(i == (row-1))
				prev = accum[(row+1)%2][row-2];
			else
				prev = accum[(row+1)%2][i] > accum[(row+1)%2][i-1] ? accum[(row+1)%2][i] : accum[(row+1)%2][i-1];

			accum[row%2][i] = input + prev;
		}
	}

	infile.close();

	// Find max value from 100th row
	row = 0;
	for(i=0; i<101; i++)
		if(accum[0][i] > row)
			row = accum[0][i];

	cout << "\n\n	Max total = " << row;

	stop_timer = clock();
	cout << "\n\n	Time taken : " << stop_timer-start_timer << " ms\n\n";

	return 0;
}
