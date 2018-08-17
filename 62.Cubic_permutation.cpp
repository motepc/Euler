/*

Another algo is
Calculate all cubes just once, store them in string[n] in 10 digit freq format.
Compare to find 5 matches.

It will be optimised solution.

*/


#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>


using namespace std;



int mark_digit(int num, long long* freq, long long* offset)
{
	int digit;
	unsigned long long temp = (unsigned long long)num*num*num;

	*freq = 0;

	digit = 0;
	while(temp>0)
	{
		digit++;
		*freq += offset[temp%10];
		temp = temp/10;
	}

	return digit;
}


bool check_match(int first, long long* offset)
{
	int i, digit, next = first+1, counter = 0;
	long long orig, current;

	digit = mark_digit(first, &orig, offset);

	while(mark_digit(next, &current, offset) == digit)
	{
		if(orig == current)
		{
			counter++;
			//printf("	Found %d = %lld with %d = %lld		Counter = %d\n\n", next, (unsigned long long)next*next*next, first, (unsigned long long)first*first*first, counter);
		}

		if(counter == 4)
			return 1;

		next++;
	}

	return 0;
}


int main()
{
	int start = clock(), stop;
	bool found = 0;
	int i, first = 345;
	long long offset[10], temp = 1;

	for(i=0; i<10; i++)
	{
		offset[9-i] = temp;
		temp *= 10;
	}

	while(found == 0)
	{
		found = check_match(first, &offset[0]);

		first++;
	}

	stop = clock();

	printf("\n\n	%d	%lld\n\n", first-1, (long long)(first-1)*(first-1)*(first-1));

	cout << "\n\n	Time taken : " << stop-start << " ms\n\n";

	return 0;

}
