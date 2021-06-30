#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

std::pair<u64, u64> getPos(u64 N, u64 M, u64 pos)
{
    u64 W = M;
    u64 H = N;

    u64 x = pos % W;
    u64 y = pos / W;

    return make_pair(x, y);
}

u64 T[200];

u64 rightUpDiag(u64 N, u64 M, u64 pos)
{
    u64 W = M;
    u64 H = N;

    pair<u64, u64> p = getPos(N, M, pos);

    u64 x = get<0>(p);
    u64 y = get<1>(p);


    u64 t = pos + 2*W + 2;

    if(x+1 > W - 2 || y+1 > H - 2 || T[t] != 0)
        return INF;

    return t;
}

u64 srightUpDiag(u64 N, u64 M, u64 pos)
{
    u64 W = M;
    u64 H = N;

    u64 t = pos + W + 1;

    return t;
}

u64 leftUpDiag(u64 N, u64 M, u64 pos)
{
    u64 W = M;
    u64 H = N;

    pair<u64, u64> p = getPos(N, M, pos);

    u64 x = get<0>(p);
    u64 y = get<1>(p);

    u64 t = pos + 2*W - 2;
    
    if(x < 2 || y+1 > H - 2 || T[t] != 0)
        return INF;
    
    return t;
}

u64 sleftUpDiag(u64 N, u64 M, u64 pos)
{
    u64 W = M;
    u64 H = N;

    u64 t = pos + W - 1;
    
    return t;
}

u64 rightDownDiag(u64 N, u64 M, u64 pos)
{
    u64 W = M;
    u64 H = N;

    pair<u64, u64> p = getPos(N, M, pos);

    u64 x = get<0>(p);
    u64 y = get<1>(p);

    u64 t = pos - 2*W + 2;
    
    if(x+1 > W - 2 || y < 2 || T[t] != 0)
        return INF;

    return t;
}

u64 srightDownDiag(u64 N, u64 M, u64 pos)
{
    u64 W = M;
    u64 H = N;

    u64 t = pos - W + 1;
    
    return t;
}

u64 leftDownDiag(u64 N, u64 M, u64 pos)
{
    u64 W = M;
    u64 H = N;

    pair<u64, u64> p = getPos(N, M, pos);

    u64 x = get<0>(p);
    u64 y = get<1>(p);

    u64 t = pos - 2*W - 2;

    if(x < 2 || y < 2 || T[t] != 0)
        return INF;

    return t;
}

u64 sleftDownDiag(u64 N, u64 M, u64 pos)
{
    u64 W = M;
    u64 H = N;

    u64 t = pos - W - 1;

    return t;
}

u64 eat(u64 N, u64 M, u64 p, u64* v)
{
    u64 rUp     = rightUpDiag(N, M, p);
    u64 lUp     = leftUpDiag(N, M, p);
    u64 rDown   = rightDownDiag(N, M, p);
    u64 lDown   = leftDownDiag(N, M, p);

    u64 best = 0;

    if(rUp != INF && T[srightUpDiag(N, M, p)] == 2)
    {
        T[srightUpDiag(N, M, p)] = 0;
        T[p]    = 0;
        T[rUp]  = 1;
        best = max(1 + eat(N, M, rUp, v), best);
        T[srightUpDiag(N, M, p)] = 2;
        T[p]    = 1;
        T[rUp]  = 0;
    }

    if(lUp != INF && T[sleftUpDiag(N, M, p)] == 2)
    {
        T[sleftUpDiag(N, M, p)] = 0;
        T[p]    = 0;
        T[lUp]  = 1;
        best = max(1 + eat(N, M, lUp, v), best);
        T[sleftUpDiag(N, M, p)] = 2;
        T[p]    = 1;
        T[lUp]  = 0;
    }

    if(rDown != INF && T[srightDownDiag(N, M, p)] == 2)
    {
        T[srightDownDiag(N, M, p)] = 0;
        T[p]    = 0;
        T[rDown]  = 1;
        best = max(1 + eat(N, M, rDown, v), best);
        T[srightDownDiag(N, M, p)] = 2;
        T[p]    = 1;
        T[rDown]  = 0;
    }

    if(lDown != INF && T[sleftDownDiag(N, M, p)] == 2)
    {
        T[p]       = 0;
        T[lDown]   = 1;
        T[sleftDownDiag(N, M, p)] = 0;
        best = max(1 + eat(N, M, lDown, v), best);
        T[sleftDownDiag(N, M, p)] = 2;
        T[p]    = 1;
        T[lDown]  = 0;
    }

    return best;
}

void solve(u64 N, u64 M)
{
    u64 best = 0;
    u64 a[200], b[200], c[200], d[200];

    for(int i=0; i<200; i++)
    {
        memset(a, 0, sizeof(u64)*200);
        
        a[i] = 1;
        
        if(T[i] == 1)
        {
            u64 tmp = eat(N, M, i, a);
            if(tmp > best)
                best = tmp;
        }
    }

    std::cout << best << std::endl;
}

int main() {
    u64 N, M;

    while(scanf("%lu %lu\n", &N, &M) == 2 && N != 0 && M != 0) {
        for(int i=0; i<200; i++)
            T[i] = 0;
        for(int i=0; i<N*M; i++)
        {
            pair<u64, u64> p = getPos(N, M, i);
            
            u64 x = get<0>(p);
            u64 y = get<1>(p);

            if(y%2 == 0)
            {
                if(i%2 == 0)
                {
                    scanf("%lu", &T[i]);
                }
            }
            
            if(y%2 == 1)
            {
                if(i%2 == 0)
                {
                    if(M%2 == 0)
                    {
                        scanf("%lu", &T[i + 1]);   
                    }
                    else
                    {
                        scanf("%lu", &T[i]);
                    }
                }
            }
        }

        solve(N, M);
    }

    return 0;
}