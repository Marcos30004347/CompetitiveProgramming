#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

// #define INF 0x3f3f3f3f
#define INF 0xf3f3f3f3

bool    G[1000000];
u64     D[1000000];
i64     Z[2000];

i64 idx(u64 l, u64 c) {
    return (l-1)*1000 + (c-1);
}

u64 shortest_path(i64 A, i64 B, i64 N)
{
    queue<i64> q;
    q.push(A);

    for(int i=0; i<1000000; i++)
        D[i] = -1;

    D[idx(A, A)] = Z[A-1];
    
    while(q.size())
    {
        i64 v = q.front();
        q.pop();

        for(i64 i=1; i<=N; i++)
        {
            if(G[idx(v, i)] && D[idx(A, i)] > D[idx(A, v)] + Z[i-1])
            {
                D[idx(A, i)] = D[idx(A, v)] + Z[i-1];
                q.push(i);
            }
        }
    }

    return D[idx(A, B)];
}


int main() {
    i64 N, M, K, A;
    f64 P;

    while(scanf("%li %li %li %lf\n", &N, &M, &K, &P) == 4)
    {
        memset(Z, 0, sizeof(i64)*2000);
        memset(G, 0, sizeof(bool)*1000000);

        i64 i, j;
        for(int e=0; e<M; e++)
        {
            scanf("%li %li\n", &i, &j);
            G[idx(i,j)] = true;
            G[idx(j,i)] = true;
        }
        scanf("%li", &A);
    
        i64 a;
        for(int e=0; e<A; e++)
        {
            scanf("%li", &a);
            Z[a-1] += 1;
            // printf("%li ", Z[a-1]);
        }
        // printf("\n");
        i64 S, E;

        scanf("\n%li %li\n", &S, &E);

        u64 s = shortest_path(S, E, N);
    
        if(s - K < 0)
        {
            printf("0.000\n");
        } else 
        {
            printf("%.3lf\n", pow(P, s));
        }
    }

    return 0;
}