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

u64 fact(u64 i)
{
    if(i == 1 || i == 0)
        return 1;

    return fact(i-1)*i;
}

u64 comb(u64 n, u64 k) {
    return fact(n)/(fact(k)*fact(n-k));
}

int main() {
    u64 N;

    scanf("%lu", &N);

    u64 k = 0;
    u64 s = sqrt(N) + 1;

    for(i64 i = 2; i <= s; i++)
    {
        bool f = false;

        while(N%i == 0 && N != 1)
        {
            f = true;
            N = N/i;
        }
        
        if(f) k++;
    }

    if(N != 1)
        k++;
    
    u64 r = 0;

    for(int i=2; i<=k; i++)
        r += comb(k, i);

    std::cout << r << std::endl;
    return 0;
}