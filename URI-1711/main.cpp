#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <array>
#include <queue>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

vector<vector<array<u64, 2>>> Graph;
vector<array<u64, 3>> Edges;


i64  Distance[10000];
i64  Parent[10000];

i64  CycleLength[10000];
i64  Cache[10000];
bool Visitado[10000];

i64 parent[10000];
i64 score[10000];

i64 find(i64 i)
{
    if(parent[i] == -1 || parent[i] == i)
        return i;

    parent[i] = find(parent[i]);

    return parent[i];
}

void unify(i64 i, i64 j)
{
    if(score[i] < score[j])
        parent[i] = j;
    else if(score[i] > score[j])
        parent[j] = i;
    else
    {
        parent[j] = i;
        score[i] = score[i] + 1;
    }
}

std::vector<array<u64, 3>> get_cycles(u64 V, vector<array<u64, 3>> Edges)
{
    std::vector<array<u64, 3>> cycles_edges;

    for(i64 i=0; i<Edges.size(); i++)
    {
        u64 a = Edges[i][1];
        u64 b = Edges[i][2];

        if(find(a) == find(b))
            cycles_edges.push_back(Edges[i]);
        else
            unify(find(a), find(b));
    }
    
    return cycles_edges;
}


u64 cycle_length(u64 s)
{
    queue<u64> Q;

    for(i64 i=0; i<10000; i++)
    {
        Visitado[i] = false;
        Cache[i] = 0;
    }

    for(i64 i=0; i<Graph[s].size(); i++)
    {
        Q.push(Graph[s][i][0]);
        Cache[Graph[s][i][0]] = Graph[s][i][1];
    }


    while (Q.size())
    {
        u64 v = Q.front();
        Visitado[v] = true;
        Q.pop();

        for(i64 i=0; i<Graph[v].size(); i++)
        {
            Cache[Graph[v][i][0]] = Cache[v] + Graph[v][i][1];

            if(!Visitado[Graph[v][i][0]])
            {
                Q.push(Graph[v][i][0]);
            }
        }

        if(v == s)
            break;
    }

    return Cache[s];
}

void djikstra(u64 s, u64 l)
{
    u64 minimum_distance = INF;

    queue<u64> Q;

    Q.push(s);

    for(int i=0; i<10000; i++)
        Distance[i] = INF;

    Distance[s] = 0;

    while (Q.size())
    {
        u64 curr = Q.front();
        Q.pop();
        
        for(int e=0; e<Graph[curr].size(); e++)
        {
            u64 to = Graph[curr][e][0];
            u64 w = Graph[curr][e][1];
    
            if(Distance[to] > Distance[curr] + w)
            {
                Parent[to] = curr;
                Distance[to] = Distance[curr] + w;
                Q.push(to);
            }
        }
    }
}

int main() {
    u64 S, T;

    while(scanf("%lu %lu\n", &S, &T) == 2)
    {
        for(int i=0; i<10000; i++)
        {
            parent[i] = -1;
            score[i] = 0;
            CycleLength[i] = INF;
        }

        Graph.clear();
        Edges.clear();

        for(int i=0; i<S; i++)
            Graph.push_back(vector<array<u64, 2>>());

        for(i64 i=0; i<T; i++)
        {
            u64 A, B, Cycles;

            scanf("%lu %lu %lu\n", &A, &B, &Cycles);

            Edges.push_back({Cycles, A-1, B-1});

            Graph[A-1].push_back({ B-1, Cycles });
            Graph[B-1].push_back({ A-1, Cycles });
        }

        vector<array<u64, 3>> cycles_edges = get_cycles(S, Edges);

        for(u64 k=0; k<cycles_edges.size(); k++)
        {
            u64 a = cycles_edges[k][1];
            u64 b = cycles_edges[k][2];

            array<i64, 2> t;
        
            CycleLength[a] = cycle_length(a);
            CycleLength[b] = cycle_length(b);
        
        }

        u64 Q;

        bool calc_cycles_lengths = false;
    
        scanf("%lu\n", &Q);
        while(Q--)
        {
            u64 start, length;
            scanf("%lu %lu\n", &start, &length);
            
            djikstra(start-1, length);

            u64 min_dist = INF;

            for(u64 k=0; k<cycles_edges.size(); k++)
            {
                u64 a = cycles_edges[k][1];
                u64 b = cycles_edges[k][2];
                if(Parent[b] == a)
                {
                    
                }
                else if(Parent[a] == b)
                {

                }
                else 
                {

                }
                // u64 dist = INF;

                // dist = 2*Distance[cycles_edges[k][1]] + CycleLength[cycles_edges[k][1]];

                // if(CycleLength[cycles_edges[k][1]] >= length && min_dist > dist)
                //     min_dist = dist;

                // dist = 2*Distance[cycles_edges[k][2]] + CycleLength[cycles_edges[k][2]];

                // if(CycleLength[cycles_edges[k][2]] >= length && min_dist > dist)
                //     min_dist = dist;

            }

            if(min_dist == INF)
                std::cout << -1 << std::endl;
            else
                std::cout << min_dist << std::endl;
        }
    }

    return 0;
}