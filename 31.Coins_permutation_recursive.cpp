/*

	Using the coins of denominations 200p, 100p, 50p, 20p, 10p, 5p, 2p, 1p
	in how many ways we can collect 200p using any number of coins of any denominations.

*/

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;



int ways(int* denom, int loc, int target)
{
	if(loc > 7)
		return 0;

	if(target < 0)
		return 0;

	if(target == 0)
		return 1;

	return (ways(denom, loc, target-*(denom+loc)) + ways(denom, loc+1, target));
}


int main()
{
	int counter, start = 0, target = 200;
	int denom[8] = {200, 100, 50, 20, 10, 5, 2, 1};

	counter = ways(denom, start, target-denom[start]) + ways(denom, start+1, target);

	printf("\n\n	%d\n", counter);

	return 0;
}
