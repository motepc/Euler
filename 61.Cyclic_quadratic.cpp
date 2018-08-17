#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;



const int coeff[5][3] = { 	1, 0, 1,
							3, 1, 2,
							2, 1, 1,
							5, 3, 2,
							3, 2, 1
						 };


bool check_discri(int n, int val)
{
	int temp, discri;

	n -= 4;
	discri = coeff[n][1]*coeff[n][1] + 4*coeff[n][0]*coeff[n][2]*val;
	temp = (int)(sqrt(discri));

	if(discri == (temp*temp))
	{
		discri = coeff[n][1] + temp;
		temp = 2*coeff[n][0];

		if(discri%temp == 0)
			return 1;
	}

	return 0;
}


bool next_cycle(int* poly, int* chain, int current)
{
	int i, j, n, val;
	bool found, done;

	val = chain[current-1]%100;

	if(current == 6)
	{
		n = (int)(chain[0]/100);

		if(val == n)
			return 1;

		return 0;
	}

	val = val*100;
	for(i=10; i<100; i++)
	{
		n = 4;
		while(n < 9)
		{
			found = 0;
			for(j=0; j<(current-1); j++)
				if(n == poly[j])
					found = 1;

			if(found == 0)
			{
				if(check_discri(n, val+i))
				{
					poly[current-1] = n;
					chain[current] = val+i;

					done = next_cycle(&poly[0], &chain[0], current+1);

					if(done == 1)
						return 1;
				}
			}

			n++;
		}
	}

	return 0;
}


int main()
{
	int chain[6], poly[5], current, n = 44;
	bool found = 0;

	while(found == 0)
	{
		n++;
		chain[0] = (n*(n+1))/2;

		current = chain[0]%100;

		if(current > 9)
		{
			current = 1;
			found = next_cycle(&poly[0], &chain[0], current);
		}
	}

	current = 0; printf("\n\n");
	for(n=0; n<6; n++)
	{
		current += chain[n];
		printf("	%d", chain[n]);
	}
	printf("\n\n	Total = %d\n\n", current);

	return 0;

}
