#include <iostream>
#include <cmath>

#define Limit 1500000
#define Half ((Limit>>1)+1)



int gcd(int m, int n)
{
    int temp;

    while(n != 0)
    {
        temp = n;
        n = m%temp;
        m = temp;
    }

    if(m == 1)
        return 1;
    else
        return 0;
}

int main()
{
    int m, n, k, x, y, L, len_freq[Half] = {0};

    // m and n should be co-prime and both of them are not odd.
    for(m=1; ; m=m+2)
    {
        if((2*m*(m+2)) > Limit)
        {
            //std::cout << "  Outer break at m = " << m << "\n";
            break;
        }

        for(n=2; ; n=n+2)
        {
            if(m < n)
            {
                x = n;
                y = m;
            }
            else
            {
                x = m;
                y = n;
            }

            L = 2*x*(x+y);
            //Because L = a+b+c, where a = x*x - y*y; b = 2*x*y; c = x*x + y*y;
            if(L > Limit)
            {
                //std::cout << "  Inner break at n = " << n << "\n";
                break;
            }

            if(gcd(x,y)) // If both are co-prime of each other
            {
                k = 1;
                while(k*L <= Limit)
                {
                    len_freq[(k*L)>>1]++;

                    k++;
                }
                //std::cout << "  Normal break at L = " << k*L << "\n";
                //a = x*x - y*y; b = 2*x*y; c = x*x + y*y;
                //std::cout << "  " << x << "  " << y << "    -   " << a << " " << b << " " << c << "\n";
            }
        }
    }

    L = 0;
    for(m=0; m < Half; m++)
        if(len_freq[m] == 1)
            L++;

    std::cout << "\n    Ans = " << L << "\n";

    return 0;
}
