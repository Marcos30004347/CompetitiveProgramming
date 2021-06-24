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

char l[1000000];



void knapsack(i64 W, i64 N, i64* weights, i64* values)
{
    i64 M[1000][1000];

    for(int c=0; c<=W; c++)
        M[0][c] = 0;
    for(int i=0; i<=N; i++)
        M[i][0] = 0;

    for(i64 item = 1; item <= N; item++)
    {
        for(i64 capacity = 1; capacity <= W; capacity++)
        {
            if(capacity >= weights[item])
            {
                M[item][capacity] = std::max(M[item - 1][capacity], M[item - 1][capacity - weights[item]] + values[item]);
            }
            else 
            {
                M[item][capacity] = M[item - 1][capacity];
            }
        }
    }

}

int main() {
    u64 N;
    scanf("%lu\n", &N);

    while (N--)
    {
        u64 pac;
        scanf("%lu\n", &pac);
        
        std::vector<std::array<u64, 2>> pacs;
        
        for(i64 i=0; i<pac; i++)
        {
            u64 qt, peso;
            scanf("%lu %lu\n", &qt, &pac);
            pacs.push_back({ qt, peso });
        }
    }
    

    return 0;
}