#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string.h>
#include <iomanip> 
using namespace std;

typedef long long i64;

#define INF 0xf3f3f3f3

i64 M[100][100];
i64 L[100];

i64 solve(i64 arr[], i64 n, i64 k)
{
    i64 sum = 0;

    for (i64 i = 0; i < n; i++)
        M[0][i] = 1;
 
    for (i64 l = 1; l < k; l++)
    {
        for (i64 i = l; i < n; i++)
        {
            M[l][i] = 0;
            
            for (i64 j = l - 1; j < i; j++)
            {
                if (L[j] < L[i])
                {
                    M[l][i] += M[l - 1][j];
                }
            }
        }
    }
 
    for (i64 i = k - 1; i < n; i++)
        sum += M[k - 1][i];
 
    return sum;
}
 

int main()
{
    while(true)
    {
        i64 n, k;
        
        scanf("%lli %lli\n", &n, &k);
        
        if(n==0 && k==0) break;
        
        for(i64 i=0; i<n; i++)
        {
            scanf("%lli", &L[i]);
        }

        std::cout << solve(L, n, k) << "\n";

        // for(int j=0; j<=n; j++)
        //     std::cout << setw(6) << L[j] << " ";
        // std::cout << "\n";

        // for(int j=1; j<=k; j++)
        // {
        //     std::cout << setw(6) << j << " ";

        //     for(int i=1; i<=n; i++)
        //     {
        //         std::cout << setw(6) << M[j][i] << " ";
        //     }
        //     std::cout << "\n";
        // }
        // std::cout <<"===============\n";


    }
    return 0;
}