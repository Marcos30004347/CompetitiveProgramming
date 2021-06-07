#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <string>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

u64 split(u64 f, u64 t, string n)
{
    return (u64)atoll(n.substr(f, t-f).c_str());
}

bool solve(u64 N, u64 V, u64 l, u64 r, u64 i, string* names, string* sells, u64** pos, u64 k) {
    if(i == V)
    {
        u64 vals[N+1];

        for(int j=0; j<=N; j++)
            vals[j] = 0;

        for(int v=0; v<V; v++)
        {
            for(int s=1; s<=N; s++)
            {
                if(s < N && split(pos[v][s-1], pos[v][s], sells[v]) >= 1000)
                {
                    return false;
                }
                
                vals[s] += split(pos[v][s-1], pos[v][s], sells[v]);
            }
        }
        string total = sells[V];
        
        for(int s=1; s<=N; s++)
        {
            bool found = false;

            for(int j=0; j<=total.length(); j++)
            {
                if(split(0, j, total) == vals[s])
                {
                    total = total.substr(j, total.length());
                    found = true;

                    break;
                }
            }

            if(found == false)
            {
                break;
            }

            if(s == N && found)
            {
                for(u64 i=1; i<N; i++)
                {
                    printf("P%lu ", i);
                }
                printf("Totals\n");
                for(int v=0; v<V; v++)
                {
                    printf("%s ", names[v].c_str());
                    for(int s=1; s<=N; s++)
                    {
                        printf("%lu ", split(pos[v][s-1], pos[v][s], sells[v]));
                    }
                    printf("\n");
                }
                printf("TP ");

                for(int s=1; s<=N; s++)
                {
                    printf("%lu ",  vals[s]);
                }
                printf("\n");
                return true;
            }
        }
    
        return false;
    }

    if(k == 0)
    {
        return solve(N, V, pos[i+1][N-1], pos[i+1][N], i+1, names, sells, pos, N-1);
    }

    u64 old_left = pos[i][k-1];
    u64 old_rigth = pos[i][k];
    
    for(u64 right = l; right<r; right++)
    {
        pos[i][k-1] = old_left;
        pos[i][k]   = right;

        if(solve(N, V, pos[i][k-1], pos[i][k], i, names, sells, pos, k-1))
            return true;
    }

    pos[i][k-1] = old_left;
    pos[i][k]   = old_rigth;
    return false;
}




int main() {
    u64 C;
    scanf("%li\n", &C);
    while(C--)
    {
        char header[17];
        scanf("%s\n", header);
        
        u64 N = (strlen(header) - 6)/2;

        string names[5];
        string sells[5];

        u64 len[5];

        u64 v = 0;

        char tmp[60];
        char name[60];
        char sell[60];
        do 
        {
            scanf("%s\n", tmp);
            sscanf(tmp, "%[a-zA-Z]%[0-9]", name, sell);
    
            names[v] = name;
            sells[v] = sell;
            len[v] = strlen(tmp) - names[v].length();
        } while(names[v++] != "TP");

        u64** pos;
        pos = new u64*[5];

        for(int i=0; i<v; i++) {
            pos[i] = new u64[N+2];
    
            pos[i][0] = 0;
            for(int j=1; j<=N; j++)
                pos[i][j] = pos[i][j-1] + 1;
            pos[i][N+1] = len[i];
        }

        // for(int j=0; j<v-1; j++)
        // {
        //     for(int n=0; n<=N+1; n++)
        //     {
        //         printf("%lu ", pos[j][n]);
        //     }
        //     printf("\n");
        // }
    
        solve(N+1, v-1, pos[0][N], pos[0][N+1], 0, names, sells, pos, N);

        // printf("%s\n", header);

        // for(int i=0; i<v; i++)
        // {
        //     printf("%s %lu\n", names[i], sells[i]);
        // }

        // printf("%lu\n", N-1);

    }
    
    return 0;
}