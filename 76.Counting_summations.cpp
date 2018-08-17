/*
    p(n,k) = p(n-k,k) + p(n-1,k-1)
*/

#include <iostream>
#include <string>



int partitions(int n, int k)
{
    if((n == 0) || (k == 0) || (n < k))
        return 0;

    if((k == 1) || (n == k))
        return 1;

    return (partitions(n-k,k) + partitions(n-1,k-1));
}

int main()
{
    int i, counter = 0, n = 100;

    for(i=2; i<=n; i++)
        counter += partitions(n,i);

    std::cout << "\n Total = " << counter << "\n";

    return 0;
}
