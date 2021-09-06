#include <iostream>
#include <vector>

using namespace std;

#define n 2000000

int divs[n + 1];
int prim[n + 1];

int t[2 * n + 1];

void build()
{
    for (int i = n; i > 0; --i)
        t[i] = t[i<<1] + t[i<<1|1];
}

int query(int l, int r)
{
    int res = 0;

    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }

    return res;
}


int main()
{
    long long N;

    fill(divs,  divs + n + 1, 0);

    for(long long i = 2; i <= n; i++)
    {
        divs[i] = divs[i] + 2; // one ant itself
    
        for(long long j = i + i; j <= n; j += i)
        {
            divs[j] = divs[j] + 1;
        }
    }

    fill(prim, prim + n + 1, 1);

    prim[0] = 0;
    prim[1] = 0;

    for(long long i = 2; i <= n; i++)
    {
        if (prim[i] && (i * i) <= n) 
        {
            for(long long j = i * i; j <= n; j += i)
            {
                prim[j] = 0;
            }
        }
    }

    fill(t, t + 2 * n + 2, 0);

    for(int i = 2; i <= n; i++)
    {
        t[n + i] = prim[divs[i]];
    }

    build();

    while(scanf("%lli\n", &N) == 1)
    {
        std::cout << query(2, N + 1) << "\n";
    }

    return 0;
}