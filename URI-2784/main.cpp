#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3

i64 I[1000][1000] = { INF };
i64 D[1000] = { INF };

i64 djikstra(u64 S, u64 N)
{
    queue<u64> v;

    v.push(S);

    for(int i=0; i<1000; i++)
        D[i] = INF;

    D[S] = 0;

    while (v.size())
    {
        u64 s = v.front();
        v.pop();

        for(int i=0; i<1000; i++)
        {
            if(D[s] + I[s][i] < D[i])
            {
                D[i] = D[s] + I[s][i];

                v.push(i);
            }
        }
    }

    i64 biggest_dist = 0;
    i64 lowest_dist = INF;

    for(int i=0;i<N; i++)
    {
        if(i == S) continue;
        if(D[i] > biggest_dist)
            biggest_dist = D[i];
        if(D[i] < lowest_dist)
            lowest_dist = D[i];
    }
    return biggest_dist - lowest_dist;
}

int main() {
    u64 N, M;
    scanf("%lu %lu", &N, &M);

    for(int i=0; i<1000; i++)
        for(int j=0; j<1000; j++)
            I[i][j] = INF;

    for(int i=0; i<M; i++)
    {
        u64 ui, vi, pi;
        scanf("%lu %lu %lu", &ui, &vi, &pi);

        I[ui-1][vi-1] = pi;
        I[vi-1][ui-1] = pi;
    }

    u64 S;
    scanf("%lu", &S);
    S--;

    std::cout << djikstra(S, N) << std::endl;

    return 0;
}