/*
Using p022_names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names,
begin by sorting it into alphabetical order.
Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include <fstream>

using namespace std;


#define MAX 487
#define TOTAL 5163


int swap(string pivot, string test)
{
	int i = 1;
	while(1)
	{
		if(i >= pivot.size())
			return 0;
		if(i >= test.size())
			return 1;

		if(pivot.at(i) < test.at(i))
			return 0;
		if(pivot.at(i) > test.at(i))
			return 1;

		i++;
	}
}


int main()
{
	int i, j, freq[26], alpha;
	string input, cache[500];
	long long final, offset, sum;

	ifstream infile;
	infile.open("p023_names.txt");

	final = 0; offset = 0;
	for(alpha=0; alpha<26; alpha++)
	{
		infile.close();
		infile.open("p023_names.txt");

		i = 0;
		while(infile >> input)
			if((input.at(0)-65) == alpha)
				cache[i++] = input;

		freq[alpha] = i;

		for(i=0; i<freq[alpha]; i++)
		{
			for(j=i+1; j<freq[alpha]; j++)
			{
				if(swap(cache[i], cache[j]))
				{
					input = cache[i];
					cache[i] = cache[j];
					cache[j] = input;
				}
			}
		}

		for(i=0; i<freq[alpha]; i++)
		{
			sum = 0;
			for(j=0; j<cache[i].size(); j++)
				sum = sum + cache[i].at(j) - 64;

			final = final + sum*(offset +i+1);
			//printf("\n%s", cache[i].c_str());
		}
		offset = offset + freq[alpha];
	}

	cout << "\n	" << final << "\n";
	infile.close();
	return 0;
}
