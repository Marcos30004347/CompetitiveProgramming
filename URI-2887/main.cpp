#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

vector<vector<int>> G;

vector<vector<int>> dp;

void bfs(int curr, vector<int>& level, vector<int>& path)
{
    queue<pair<int, int>> q;

    q.push({curr, -1});

    level[curr] = 0;

    while (q.size())
    {
        int curr = q.front().first;
        int from = q.front().second;

        q.pop();
        
        for(int to : G[curr])
        {
            if(from == to) 
                continue;
            
            path[to] = curr;
            level[to] = level[curr] + 1;

            q.push({ to, curr });
        }
    }
    
}

int main()
{
    int i, f, t;
    unsigned N, Q, A, B, C, D;

    scanf("%u %u\n", &N, &Q);

    vector<int> from = vector<int>(N);
    vector<int> level = vector<int>(N);
    vector<bool> visi = vector<bool>(N);

    fill(from.begin(), from.end(), -1);
    fill(level.begin(), level.end(), -1);

    for(i = 0; i<N; i++)
    {
        G.push_back(vector<int>());
    }

    for(i = 0; i<N - 1; i++)
    {
        scanf("%u %u\n", &f, &t);
        G[f - 1].push_back(t - 1);
        G[t - 1].push_back(f - 1);
    }

    for(i = 0; i<N - 1; i++)
    {
        if(G[i].size() > 1)
        {
            break;
        }
    }

    bfs(i, level, from);

    for(i = 0; i<Q; i++)
    {
        scanf("%u %u %u %u\n", &A, &B, &C, &D);

        A = A - 1;
        B = B - 1;
        C = C - 1;
        D = D - 1;
    
        fill(visi.begin(), visi.end(), false);
    
        while(A != B)
        {
            if(level[A] > level[B])
            {
                visi[A] = true;
                A = from[A];
            }
            else if(level[A] < level[B]) 
            {
                visi[B] = true;
                B = from[B];
            }
            else 
            {
                visi[A] = true;
                visi[B] = true;

                A = from[A];
                B = from[B];
            }
        }

        visi[A] = true;
        visi[B] = true;
        
        int k = 0;

        while(C != D)
        {
            if(level[C] > level[D])
            {
                if(visi[C]) k = k + 1;
                C = from[C];
            }
            else if(level[C] < level[D]) 
            {
                if(visi[D]) k = k + 1;
                D = from[D];
            }
            else 
            {
                if(visi[D]) k = k + 1;
                if(visi[C]) k = k + 1;

                C = from[C];
                D = from[D];
            }
        }

        if(visi[C]) k = k + 1;

        std::cout << k << "\n";
    }

    return 0;

}