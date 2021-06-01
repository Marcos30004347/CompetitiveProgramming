#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

vector<u64> op;
vector<u64> x;

void solve()
{
    bool stack      = true;
    bool queue      = true;
    bool pqueue     = true;
    
    list<u64> bag;
 
    for(int i=0; i<op.size(); i++)
    {
        if(op[i] == 1)
        {
            bag.insert(bag.end(), x[i]);
        }
        else if(op[i] == 2)
        {
            list<u64> ord_bag = bag;
            ord_bag.sort();
        
            if(x[i] != ord_bag.back())
                pqueue = false;
            if(x[i] != bag.front())
                queue = false;
            if(bag.back() != x[i])
                stack = false;
            bag.remove(x[i]);
        }
    }

    if(!queue && !pqueue && !stack)
        printf("impossible\n");
    if(queue + pqueue + stack >= 2) 
        printf("not sure\n");
    else if(stack)
        printf("stack\n");
    else if(queue)
        printf("queue\n");
    else if(pqueue)
        printf("priority queue\n");
}

int main() {
    u64 n;
 

    while(scanf("%lu\n", &n) == 1)
    {
        op.clear();
        x.clear();
    
        u64 o, v;
        for(int i=0; i<n; i++)
        {
            scanf("%lu %lu\n", &o, &v);
            
            op.push_back(o);
            x.push_back(v);
        }


        solve();

    }

    return 0;
}