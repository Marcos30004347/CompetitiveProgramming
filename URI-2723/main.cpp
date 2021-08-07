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

i64 dp[6][10000];
i64 w[10000];

i64 solve(i64 N, i64 l, i64 r, i64 i)
{
    i64 diff = abs(l - r);

    if(diff > 5)
        return 0;
    
    if(i == N)
        return 1;

    if(dp[diff][i] != -1)
        return dp[diff][i];
    
    dp[diff][i] = max(solve(N, l + w[i], r, i+1), solve(N, l, r + w[i], i+1));

    return dp[diff][i];
}

int main()
{

    u64 T, N;
    scanf("%li\n", &T);
    while(T--)
    {
        scanf("%li\n", &N);
        for(i64 i=0; i<N; i++)
        {
            scanf("%li", &w[i]);
        }
        memset(dp, -1, sizeof(dp));
        i64 v = solve(N, 0, 0, 0);
        if(v == 0)
            std::cout << "Ho Ho Ho!\n";
        else
            std::cout << "Feliz Natal!\n";
    }

}