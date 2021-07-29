#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

i64 W[110];
i64 V[110];

i64 M[110][110];

i64 knapsack(i64 n, i64 w)
{
    for(i64 j=0;j<=w; j++)
        M[0][j] = 0;
    for(i64 i=0;i<=n; i++)
        M[i][0] = 0;

    for(i64 i=1;i<=n; i++)
    {
        for(i64 j=1;j<=w; j++)
        {
            if(W[i-1] > j)
                M[i][j] = M[i-1][j];
            else
                M[i][j] = std::max(M[i-1][j], M[i-1][j - W[i-1]] + V[i-1]);
        }
    }

    return M[n][w];
}

int main()
{
    u64 T;
    scanf("%lu\n", &T);
    while (T--)
    {
        u64 N;
    
        scanf("%lu\n", &N);
    
        for(i64 i=0; i<N; i++)
            scanf("%lu %lu\n", &V[i], &W[i]);

        u64 K, R;

        scanf("%lu %lu\n", &K, &R);

        i64 V = knapsack(N, K);

        if(knapsack(N, K) >= R)
        {
            std::cout << "Missao completada com sucesso" << std::endl;
        }
        else
        {
            std::cout << "Falha na missao" << std::endl;
        }
    }
    
    return 0;
}