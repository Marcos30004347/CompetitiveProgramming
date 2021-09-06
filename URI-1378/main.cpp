#include <iostream>

long long x[1000];
long long y[1000];

int main()
{
    long long N;

    while(scanf("%lli\n", &N) == 1)
    {
        for(int i=0; i<N; i++)
        {
            scanf("%lli %lli\n", x + i, y + i);
        }

    }
    return 0;
}