/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.


Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;


#define MAX 1000



int main()
{
	int i, j, snap, counter, max_count, output;
	bool rem[MAX];

	max_count = 0;
	for(i=2; i<MAX; i++)
	{
		for(j=0; j<MAX; j++)
			rem[j] = 0;

		j = 1; counter = 0; snap = 0;
		while(snap != j)
		{
			if(rem[j] == 1)
			{
				if(counter == 0)
					snap = j;

				counter++;
			}
			else
				rem[j] = 1;

			j = j*10;
			j = j%i;
		}

		if(counter > max_count)
		{
			max_count = counter;
			output = i;
		}
	}

	printf("\n\n	%d\n", output);

	return 0;
}
