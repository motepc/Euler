#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


#define MAX 1000001


using namespace std;



long long fact(int n, int r)
{
	if(n == r)
		return 1;

	return (n*fact(n-1,r));
}


long long comb(int n, int r)
{
	return (fact(n,n-r)/fact(r,0));
}


int main()
{
	int total = 0, num = 23, r;

	while(num < 101)
	{
		r = 2;

		while(comb(num,r) < MAX)
			r++;

		total += num - 2*r + 1;

		num++;
	}

	printf("\n\n	%d\n", total);

	return 0;
}
