#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <array>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

int main()
{
    i64 N;

    i64 A[50100];
    
    A[0] = 0;
    
    scanf("%lu\n", &N);
    
    A[N+1] = 0;
    
    
    for(i64 i=1; i<=N; i++)
        scanf("%lu\n", &A[i]);

    i64 h, heigth = 0;

    for(i64 i=1; i<=N; i++)
    {
        if(A[i] > A[i-1])
        {
            A[i] = A[i-1]+1;
        }
    }
    for(i64 i=N; i>=1; i--)
    {
        if(A[i] > A[i+1])
        {
            A[i] = A[i+1]+1;
        }
    }
    i64 best = 0;
    for(i64 i=0; i<N; i++)
    {
        best = std::max(A[i], best);
    }
    //     h = std::min(i+1, A[i]);

    //     int idx_l = i;
    //     while(h) h = std::min(A[--idx_l], h-1);
    //     idx_l++;

    //     h = std::min(N - i, i-idx_l+1);

    //     int idx_r = i;
    //     while(h) h = std::min(A[++idx_r], h-1);
    //     idx_r--;

    //     heigth = std::max(heigth, idx_r-i+1);
    // }

    std::cout << best << std::endl;

    return 0;
}