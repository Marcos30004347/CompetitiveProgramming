#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

vector<vector<i64>> adj         = vector<vector<i64>>(0);
vector<vector<i64>> adjc        = vector<vector<i64>>(0);
vector<vector<i64>> capacity    = vector<vector<i64>>(0);

int aumented_path(i64 s, i64 t, vector<i64>& parent)
{
    fill(parent.begin(), parent.end(), -1);

    parent[s] = -2;

    queue<pair<i64,i64>> q;

    q.push({s, INF});

    while(q.size())
    {
        i64 curr = q.front().first;
        i64 flow = q.front().second;

        q.pop();

        for(i64 v : adj[curr])
        {

            if(parent[v] == -1 && capacity[curr][v] > 0)
            {
                parent[v] = curr;

                i64 f = min(flow, capacity[curr][v]);

                if(v == t) return f;

                q.push({ v, f });
            }
        }
    }

    return 0;
}



int flood(i64 n, i64 s, i64 t, vector<i64>& parent)
{
    // std::cout << n << std::endl;
    fill(parent.begin(), parent.end(), -1);

    parent[s] = -2;

    queue<tuple<i64,i64,i64, i64>> q;

    q.push(make_tuple(s, 0, -1, 1));
    q.push(make_tuple(-1, 0, -1, 0));
    
    u64 level = 1;

    i64 curr = -1;
    i64 amnt = -1;
    i64 from = -1;
    i64 cost = -1;

    while(n > 0)
    {
        curr = std::get<0>(q.front());
        amnt = std::get<1>(q.front());
        from = std::get<2>(q.front());
        cost = std::get<3>(q.front());

        q.pop();

        if(curr == -1)
        {
            level++;

            for(i64 v: adjc[s])
                q.push(make_tuple(s, 0, -1 , level));

            q.push(make_tuple(-1, 0, -1, 0));

            if(std::get<0>(q.front()) == -1)
                break;
            else 
                continue;
        }
        
        for(i64 v : adjc[curr])
        {
            if(v != curr && capacity[v][curr] > 0)
            {
                parent[v] = curr;

                if(v == t) n -= capacity[v][curr];
                if(n == 0) break;

                q.push(make_tuple(v, capacity[v][curr], curr, cost+1));
            }
        }
    }

    std::cout << cost << std::endl;

    return 0;
}



struct gret
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

i64 flow(i64 ammount, i64 N, i64 s, i64 t)
{
    i64 flow = 0;
    i64 next_flow = 0;

    vector<i64> parent(N);

    while(next_flow = aumented_path(s, t, parent))
    {

        flow += next_flow;

        i64 curr = t;
        i64 from = -1;
        u64 dist = 0;

        while(curr != s)
        {
            i64 prev = parent[curr];
            dist++;

            capacity[prev][curr] -= next_flow;
            capacity[curr][prev] += next_flow;
            from = curr;
            curr = prev;
        }
    }

    flood(ammount, s, t, parent);

    return flow;
}

int main() {
    capacity = vector<vector<i64>>(0);
    adj      = vector<vector<i64>>(0);

    while(true)
    {
        i64 N, M, A;

        scanf("%li %li %li\n", &N, &M, &A);

        capacity = vector<vector<i64>>(N);
        adj      = vector<vector<i64>>(N);
        adjc     = vector<vector<i64>>(N);

        if(N == 0 && M == 0 && A == 0)
            break;

        for(i64 i=0; i<N; i++)
        {
            for(i64 j=0; j<N; j++)
            {
                capacity[i].push_back(0);
            }
        }

        for(i64 i=0; i<M; i++)
        {
            i64 O, D, S;
            scanf("%li %li %li\n", &O, &D, &S);

            adj[O - 1].push_back(D - 1);
            adj[D - 1].push_back(O - 1);

            adjc[O - 1].push_back(D - 1);

            capacity[O - 1][D - 1] = S;
            capacity[D - 1][S - 1] = 0;
        }

        flow(A, N, 0, N-1);

    }



    return 0;
}