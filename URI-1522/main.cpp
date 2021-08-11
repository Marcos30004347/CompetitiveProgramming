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


i64 stack[3][110];


i64 dp[101][101][101];

i64 solve(i64 n, i64 a, i64 b, i64 c)
{
    if(a==n && b==n && c==n) return 1;

    // i64 top = stack[0][a]*100 + b*100 + c;
    
    if(dp[a][b][c] != -1) return dp[a][b][c];

    if(a < n && b < n && c < n)
        if((stack[0][a] + stack[1][b] + stack[2][c])%3 == 0)
            dp[a][b][c] = max(dp[a][b][c], solve(n, a+1, b+1, c+1));

    if(dp[a][b][c] == 1) return 1;

    if(a < n && b < n)
        if((stack[0][a] + stack[1][b])%3 == 0)
            dp[a][b][c] = max(dp[a][b][c], solve(n, a+1, b+1, c));
    
    if(dp[a][b][c] == 1) return 1;
    
    if(a < n && c < n)
        if((stack[0][a] + stack[2][c])%3 == 0)
            dp[a][b][c] = max(dp[a][b][c], solve(n, a+1, b, c+1));

    if(b < n && c < n)
        if((stack[1][b] + stack[2][c])%3 == 0)
            dp[a][b][c] = max(dp[a][b][c], solve(n, a, b+1, c+1));

    if(dp[a][b][c] == 1) return 1;
    
    if(a < n)
        if((stack[0][a])%3 == 0)
            dp[a][b][c] = max(dp[a][b][c], solve(n, a+1, b, c));
    
    if(dp[a][b][c] == 1) return 1;
    
    if(b < n)
        if((stack[1][b])%3 == 0)
            dp[a][b][c] = max(dp[a][b][c], solve(n, a, b+1, c));
    
    if(dp[a][b][c] == 1) return 1;
    
    if(c < n)
        if((stack[2][c])%3 == 0)
            dp[a][b][c] = max(dp[a][b][c], solve(n, a, b, c+1));
    
    return dp[a][b][c] == 1 ? 1 : 0;
}

int main()
{
    while(true)
    {
        i64 n;
        scanf("%li\n", &n);
        
        if(n == 0) break;
        
        for(i64 i=0; i<n; i++)
            scanf("%li %li %li\n", &stack[0][i], &stack[1][i], &stack[2][i]);
    
        stack[0][n] = -1;
        stack[1][n] = -1;
        stack[2][n] = -1;

        memset(dp, -1, sizeof(dp));
    
        std::cout << solve(n,0,0,0) << "\n";
    }

    return 0;
}