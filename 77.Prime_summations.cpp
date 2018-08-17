#include <iostream>
#include <cmath>



int sum(int n, int start, int prime_num, int* prime)
{
    int i, counter = 0;

    if(n == 0)
        return 1;
    if(n == 1)
        return 0;

    for(i=start; i<prime_num; i++)
    {
        if(n >= prime[i])
            counter += sum(n-prime[i], i, prime_num, prime);
        else
            break;
    }

    return counter;
}

bool is_prime(int n, int* prime)
{
    int i=0, limit = sqrt(n);

    while(prime[i] <= limit)
    {
        if(n%prime[i] == 0)
            return 0;

        i++;
    }

    return 1;
}

int main()
{
    int counter, prime_num, n, prime[1000];

    prime_num = 1; prime[0] = 2;
    for(n=3; ; n++)
    {
		/*If (is_prime) part is kept just before the end of 'for loop',
		it will give exact number ways of sum.
		Because, in that case it will exclude self.*/
        if(is_prime(n, prime))
        {
            prime[prime_num] = n;
            prime_num++;
        }

        counter = sum(n, 0, prime_num, prime);

        if(counter > 5000)
            break;
    }

    std::cout << "\n Num = " << n << "\n";

    return 0;
}
