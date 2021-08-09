#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <string.h>
#include <iomanip>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

u64 capacity[1000][1000];

vector<u64> adj[1000];

u64 bfs(u64 s, u64 e, std::vector<u64> &parent)
{
    fill(parent.begin(), parent.end(), -1);

    parent[s] = -2;
 
    queue<pair<u64, u64>> q;

    q.push({s, INF});

    while(q.size())
    {
        u64 n    = q.front().first; 
        u64 flow = q.front().second; 

        q.pop();

        for(u64 to: adj[n])
        {
            if(parent[to] == -1 && capacity[n][to] > 0)
            {
                parent[to] = n;

                i64 min_flow = min(capacity[n][to], flow);
                
                if(to == e)
                {
                    return min_flow;
                }

                q.push({to, min_flow});
            }
        }
    }

    return 0;
}

u64 flow(u64 s, u64 t)
{
    std::vector<u64> parent(1000);

    i64 flow = 0;

    i64 aument = 0;

    while(aument = bfs(s, t, parent))
    {
        flow += aument;

        i64 node = t;
        while(node != s)
        {
            i64 prev = parent[node];
            capacity[prev][node] -= aument;
            capacity[node][prev] += aument;
            node = prev;
        }
    }

    return flow;
}

int main()
{
    u64 t, n, m;
    scanf("%lu", &t);
    while(t--)
    {
        scanf("%lu %lu\n", &n, &m);

        for(int i=0; i <=1000; i++)
            adj[i].clear();

        memset(capacity, 0, sizeof(capacity));
        
        for(int i=1; i<=6; i++)
        {
            capacity[0][i] = n/6;
            adj[0].push_back(i);
        }

        for(int i=1; i<=m; i++)
        {
            char tipo[2][10];

            scanf("%s %s\n", tipo[0], tipo[1]);

            i64 a[2] = { INF, INF };

            for(i64 k=0; k<2; k++)           
            {
                if(strcmp(tipo[k], "XXL") == 0)      a[k] = 1;
                else if(strcmp(tipo[k], "XL")  == 0) a[k] = 2;
                else if(strcmp(tipo[k], "L")   == 0) a[k] = 3;
                else if(strcmp(tipo[k], "M")   == 0) a[k] = 4;
                else if(strcmp(tipo[k], "S")   == 0) a[k] = 5;
                else if(strcmp(tipo[k], "XS")  == 0) a[k] = 6;
            }

            adj[a[0]].push_back(i+6);
            adj[i+6].push_back(a[0]);

            adj[a[1]].push_back(i+6);
            adj[i+6].push_back(a[1]);

            adj[m+7].push_back(i+6);
            adj[i+6].push_back(m+7);

            capacity[a[0]][i+6] = 1;
            capacity[i+6][a[0]] = 1;
            capacity[a[1]][i+6] = 1;
            capacity[i+6][a[1]] = 1;
            capacity[i+6][m+7] = 1;
            capacity[m+7][i+6] = 1;
        }

        u64 f = flow(0, m+7);

        if(f == m)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }

}