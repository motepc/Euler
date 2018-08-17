#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;



int main()
{
	int i, j, size[2], sum, carry, add_carry, counter=0;
	string fraction[2], add;

	i = 48;
	fraction[0].append((char*)(&i), 0, 1);
	i = 49;
	fraction[1].append((char*)(&i), 0, 1);

	for(i=0; i<1000; i++)
	{
		size[0] = fraction[i%2].size();
		size[1] = fraction[(i+1)%2].size();
		add.clear();
		carry = 0; add_carry = 0;

		for(j=0; j<size[1]; j++)
		{
			if(j<size[0])
			{
				sum = carry + fraction[i%2].at(j) + 2*fraction[(i+1)%2].at(j) - 144;
				carry = sum/10;
				sum = sum%10 + 48;

				fraction[i%2].replace(j, 1,(char*)(&sum));

				sum = add_carry + sum + fraction[(i+1)%2].at(j) - 96;
				add_carry = sum/10;
				sum = sum%10 + 48;
				add.append((char*)(&sum), 0, 1);
			}
			else
			{
				sum = carry + 2*fraction[(i+1)%2].at(j) - 96;
				carry = sum/10;
				sum = sum%10 + 48;

				fraction[i%2].append((char*)(&sum), 0, 1);

				sum = add_carry + sum + fraction[(i+1)%2].at(j) - 96;
				add_carry = sum/10;
				sum = sum%10 + 48;
				add.append((char*)(&sum), 0, 1);
			}
		}
		while(j<size[0])
		{
			sum = carry + fraction[i%2].at(j) - 48;
			carry = sum/10;
			sum = sum%10 + 48;

			fraction[i%2].replace(j, 1,(char*)(&sum));

			sum = add_carry + sum - 48;
			add_carry = sum/10;
			sum = sum%10 + 48;
			add.append((char*)(&sum), 0, 1);

			j++;
		}
		while(carry > 0)
		{
			sum = carry%10 + 48;
			carry = carry/10;

			fraction[i%2].append((char*)(&sum), 0, 1);

			sum = add_carry + sum - 48;
			add_carry = sum/10;
			sum = sum%10 + 48;
			add.append((char*)(&sum), 0, 1);
		}
		while(add_carry > 0)
		{
			sum = add_carry%10 + 48;
			add_carry = add_carry/10;

			add.append((char*)(&sum), 0, 1);
		}

		if(add.size() > fraction[i%2].size())
		{
			counter++;
			printf("\n	%s/%s", add.c_str(), fraction[i%2].c_str());
		}
	}



		//fract[i%2] += 2*fract[(i+1)%2];
		//printf("\n	%d/%d", fract[0]+fract[1], fract[i%2]);

	printf("\n\n	Counter = %d\n", counter);

	return 0;

}
