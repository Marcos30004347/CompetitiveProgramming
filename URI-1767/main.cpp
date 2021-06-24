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


i64 M[1000][1000] = { 0 };

void knapsack(i64 W, i64 N, i64* weights, i64* values)
{
    for(int c=0; c<=W; c++)
        M[0][c] = 0;
    for(int i=0; i<=N; i++)
        M[i][0] = 0;

    for(i64 item = 1; item <= N; item++)
    {
        for(i64 capacity = 1; capacity <= W; capacity++)
        {
            if(capacity >= weights[item-1])
                M[item][capacity] = std::max(M[item - 1][capacity], M[item - 1][capacity - weights[item-1]] + values[item-1]);
            else 
                M[item][capacity] = M[item - 1][capacity];
        }
    }


    i64 C = W;
    i64 peso = 0;
    i64 usados = 0;

    for(int i=N; i>=0; i--)
    {
        if(M[i-1][C] < M[i][C])
        {
            C -= weights[i-1];
            peso += weights[i-1];
            usados+=1;
        }
    }

    std::cout << M[N][W] << " brinquedos" << std::endl;
    std::cout <<"Peso: "<< peso << " kg" << std::endl;
    std::cout <<"sobra(m) "<< N - usados << " pacote(s)" << std::endl;

}

int main() {
    u64 N;
    i64 W[1000];
    i64 V[1000];

    scanf("%lu\n", &N);

    while (N--)
    {
        u64 pac;
        scanf("%lu\n", &pac);
        
        for(i64 i=0; i<pac; i++)
            scanf("%lu %lu\n", &V[i], &W[i]);

        knapsack(50, pac, W, V);
        std::cout << std::endl;
    }
    
    return 0;
}