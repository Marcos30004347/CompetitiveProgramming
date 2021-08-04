#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long long i64;

#define INF 0xf3f3f3f3

u64 V[10000];
u64 N;

u64 solve(u64 l, u64 r, u64 p, u64 f_p, u64 s_p)
{
    if(f_p + s_p == N) return f_p;

    if(p == 0)
    {
        if(V[l]%2 == 0) return solve(l+1, r, (p+1)%2, f_p+1, s_p);
        if(V[r]%2 == 0) return solve(l, r-1, (p+1)%2, f_p+1, s_p);

        return max(solve(l+1, r, p+1, f_p, s_p), solve(l, r-1, p+1, f_p, s_p));
    }

    if(p == 1)
    {
        if(V[l]%2 == 0) return solve(l+1, r, (p+1)%2, f_p, s_p+1);
        if(V[r]%2 == 0) return solve(l, r-1, (p+1)%2, f_p, s_p+1);

        return max(solve(l+1, r, (p+1)%2, f_p, s_p), solve(l, r-1, (p+1)%2, f_p, s_p));
    }

    return f_p;
}

u64 M[1100][1100];
u64 _solve()
{
    u64 len = 2*N;

    for(i64 size=0; size<len; size++)
    {
        for(i64 left=0; size+left<len; left++)
        {
            u64 rigth = size + left;

            if(size == 0)
            {
                M[left][rigth] = 0;
            }
            else if(size%2 == 0)
            {
                M[left][rigth] = std::min(M[left+1][rigth], M[left][rigth-1]);
            }
            else
            {
                u64 a = 0, b = 0;

                if(V[left]%2 == 0)  a = 1;
                if(V[rigth]%2 == 0) b = 1;

                M[left][rigth] = std::max(M[left+1][rigth] + a, M[left][rigth-1] + b);
            }
        }
    }

    return M[0][len - 1];
}

int main()
{
    while(true)
    {
        scanf("%lu\n", &N);
    
        if(N == 0) break;
    
        for(int i=0; i<2*N; i++)
            scanf("%lu", &V[i]);  

        std::cout << _solve() << "\n";
    }
    return 0;
}