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

u64 D[1050];
u64 M[1050];

i64 DP[2005][1005];

// u64 solve(i64 P, u64 N, u64 i)
// {
//     if(P <= 0)
//         return 0;

//     if(i >= N)
//         return INF;

//     if(E[P][i] != INF)
//         return E[P][i];

    

//     E[P][i] = std::min(solve(P - D[i], N, i+1) + M[i], solve(P, N, i+1));

//     return E[P][i];
// }


u64 solve(i64 P, u64 N, u64 i)
{
    if(P <= 0)
        return 0;

    if(i == N)
        return INF;

    if(DP[P][i] != -1) return DP[P][i];

    DP[P][i] = min(solve(P - D[i], N, i+1) + M[i], solve(P, N, i+1));

    return DP[P][i];
}


// u64 _solve(i64 P, i64 N)
// {
//     for(int i=0; i<=P; i++)
//         E[0][i] = 0;
//     for(int i=0; i<=N; i++)
//         E[i][0] = 0;

//     u64 best =0;

//     for(int i=1; i<=N; i++)
//     {
//         for(int j=1; j<=P; j++)
//         {
//             if(D[i-1] > j)
//             {
//                 E[i][j] = E[i-1][j];
//             }
//             else
//             {
//                 E[i][j] = std::max(
//                     E[i-1][j],
//                     E[i-1][j - D[i-1]] + M[i-1]
//                 );
//             }
//         }
//     }
    
//     return E[N][P];
// }

int main()
{
    u64 N, P;

    while(scanf("%lu %lu\n", &N, &P) == 2)
    {
        for(i64 i=0; i<N; i++)
        {
            scanf("%lu %lu\n", &D[i], &M[i]);
        }


        memset(DP, -1, sizeof(DP));

        u64 v = solve(P, N, 0);

        if(v == INF)
            std::cout << -1 << "\n";
        else
           std::cout << v << "\n";


    }
    
    return 0;
}