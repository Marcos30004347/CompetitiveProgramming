#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <string.h>
#include <iomanip>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

u64 H[1000];
u64 D[1000];

f64 M[10000];
f64 U[10000];

f64 E[150][1050];

f64 solve(u64 m, u64 i, f64 V, u64 N)
{
    if(i == N)
        return 0;

    if(E[m][i] != INF)
        return E[m][i];

    if(m != 0)
        E[m][i] = H[i]/(V + D[i]) + solve(m-1, i+1, V, N);

    E[m][i] = std::min(E[m][i], H[i]/V + solve(m, i+1, V, N));

    return E[m][i];
}

int main()
{
    u64 N, K, V;

    while(scanf("%lu %lu %lu\n", &N, &K, &V) == 3)
    {
        for(i64 i=0; i<N; i++)
            scanf("%lu %lu\n", &H[i], &D[i]);

        M[0] = H[0]/(f64)V;
        U[0] = 0;

        for(i64 i=1; i<N; i++)
        {
            M[i] = H[i]/(f64)V + M[i-1];
            U[i] = 0;
        }

        for(i64 i=0; i<N; i++)
        {
            M[i] = M[N-1];
        }

        f64 T = M[N-1];
        i64 i_ = -1;

        for(i64 i=0; i<150; i++)
            for(i64 j=0; j<1050; j++)
                E[i][j] = INF;
        
        cout.precision(4);
        std::cout << std::fixed << solve(K, 0, V, N) << "\n";

    //     while(K--)
    //     {
    //         for(i64 i=0; i<N; i++)
    //         {
    //             f64 a = V + U[i]*D[i];
    //             f64 b = V + D[i] + U[i]*D[i];

    //             M[i] = T - H[i]/a + H[i]/b;
    //         }

    //         for(i64 i=0; i<N; i++)
    //         {
    //             if(T > M[i])
    //             {
    //                 T = M[i];
    //                 i_ = i;
    //             }
    //         }

    //         U[i_]++;
    //     }

    //     cout.precision(4);
    //     // for(int i=0; i<=K; i++)
    //     // {
    //     //     for(int j=0; j<N; j++)
    //     //     {
    //     //         std::cout << std::fixed << M[i][j] << " ";
    //     //     }
    //     //     std::cout << "\n";
    //     // }

    //     // std::cout << "\n";
    //     f64 best = INF;

    //     for(i64 i=0; i<N; i++)
    //         best = std::min(best, M[i]);

    //     std::cout << std::fixed << best << "\n";
    }
    return 0;
}