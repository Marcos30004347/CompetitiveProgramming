#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

i64 solve(u64 N, u64 M, vector<u64>* wired, bool* state, bool* l)
{
    i64 k = 0;
    
    for(int t=0; t<3; t++)
    {
        for(int j=0; j<N; j++)
        {
            for(u64 i : wired[j])
            {
                state[i] = !state[i];
            }
    
            bool w = true;
    
            for(int i=0; i<M; i++)
            {
                if(state[i])
                    w = false;
            }

            if(w) return k*N + j + 1;
        }
        
        k++;
    }

    return -1;
}

int main() {
    u64 N, M;
    scanf("%lu %lu", &N, &M);
    
    bool l[M];
    bool state[M];

    for(int i=0; i<M; i++)
    {
        l[i] = false;
        state[i] = false;
    }
    
    u64 L;
    scanf("%lu", &L);

    for(int i=0; i<L; i++)
    {
        u64 j;
        scanf("%lu", &j);
        
        l[j-1] = true;
        state[j-1] = true;
    }

    vector<u64> wired[N];
    for(int i=0; i<N; i++)
    {
        u64 K;
        scanf("%lu", &K);

        wired[i].reserve(K);
        for(int j=0; j<K; j++)
        {
            u64 v;
            scanf("%lu", &v);
            wired[i].push_back(v-1);
        }
    }

    std:cout << solve(N, M, wired, state, l) << std::endl;
    

    return 0;
}