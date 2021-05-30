#include <iostream>
#include <algorithm>

typedef long unsigned u64;
typedef long i64;

i64 solve(u64* l, u64 h, u64 W, u64 H, u64 count) {
    if((W*100)%h != 0)
        return INT32_MAX;

    i64 u = count; // remaining woods

    i64 r = 0; // used woods
    i64 p = 0; // filled rows    

    i64 i = count - 1; // bigger wood
    i64 j = 0;         // smaller wood

    while(i >= j && p < (W*100)/h) 
    {   
        // no woods left
        if(j > 0 && i<=j){ 
            break;
        }

        // bigger wood can fill the row
        if(l[i] == H) 
        {
            r++;
            p++;
            i--;
            u--;
        }
        // bigger and smaller woods can fill the row
        else if(l[j] + l[i] == H)
        {
            r+=2;
            p++;
            i--;
            j++;
            u-=2;
        } 
        // sum of bigger and smaller woods sizes is 
        // greater than needed
        else if(l[j] + l[i] > H)
        {
            u--;
            i--;
        }
        // sum of bigger and smaller woods sizes is 
        // less than needed
        else
        {
            u--;
            j++;
        }
    }

    if(p < W*100/h)
        return INT32_MAX;

    return r;
}

int main() {
    u64 M,N;
    while(scanf("%lu %lu\n", &M, &N))
    {
        u64 L, K;
        
        if(M == 0 && N == 0)
            break;

        scanf("%lu\n%lu\n", &L, &K);

        u64 l[K];

        for(int k=0; k<K; k++)
            scanf("%lu", &l[k]);
    
        std::sort(l, l+K);

        i64 best = std::min(
            solve(l, L, M, N, K),
            solve(l, L, N, M, K)
        );
        
        if(INT32_MAX == best)
            puts("impossivel");
        else
            printf("%li\n", best);
    }

    return 0;
}