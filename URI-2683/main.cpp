#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <tuple>
#include <set>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

vector<tuple<u64, u64, u64>> edges;
vector<tuple<u64, u64, u64>> tree_minimum;
vector<tuple<u64, u64, u64>> tree_higher;
set<u64> vertices;


i64 parent_minimum[1000000];
i64 rank_minimum[1000000];

i64 parent_higher[1000000];
i64 rank_higher[1000000];

i64 find(i64* _parent, i64 i)
{
    if(_parent[i] == -1)
        return i;

    _parent[i] = find(_parent, _parent[i]);

    return _parent[i];
}

void unify(i64* _parent, i64* _rank, i64 i, i64 j)
{
    if(_rank[i] < _rank[j])
        _parent[i] = j;
    else if(_rank[i] > _rank[j])
        _parent[j] = i;
    else
    {
        _parent[j] = i;
        _rank[i] = _rank[i] + 1;
    }
}

void spanning_trees()
{
    std::sort(edges.begin(), edges.end());

    i64 i = 0;
    
    while(tree_minimum.size() < vertices.size() - 1)
    {
        tuple<u64, u64, u64> edge = edges[i++];

        i64 a = find(parent_minimum, get<1>(edge));
        i64 b = find(parent_minimum, get<2>(edge));
    
        if(a != b)
        {
            tree_minimum.push_back(edge);
            unify(parent_minimum, rank_minimum, a, b);
        }
    }

    i = edges.size() - 1;
    while(tree_higher.size() < vertices.size() - 1)
    {
        tuple<u64, u64, u64> edge = edges[i--];

        i64 a = find(parent_higher, get<1>(edge));
        i64 b = find(parent_higher, get<2>(edge));
    
        if(a != b)
        {
            tree_higher.push_back(edge);
            unify(parent_higher, rank_higher, a, b);
        }

    }
}

int main() {
    u64 N;
    scanf("%lu", &N);

    for(int i=0; i<N; i++)
    {
        u64 a, b, w;
        scanf("%lu %lu %lu", &a, &b, &w);

        vertices.insert(a);
        vertices.insert(b);
        
        edges.push_back(make_tuple(w,a,b));
    }

    for(int i=0; i<1000000; i++)
    {
        parent_minimum[i] = -1;
        parent_higher[i] = -1;
        rank_minimum[i] = 0;
        rank_higher[i] = 0;
    }

    spanning_trees();

    u64 C = 0;
    u64 W = 0;

    for(int i=0; i<tree_higher.size(); i++)
        W += std::get<0>(tree_higher[i]);

    for(int i=0; i<tree_minimum.size(); i++)
        C += std::get<0>(tree_minimum[i]);

    std::cout << W << std::endl;
    std::cout << C << std::endl;

    return 0;
}