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

bool solve(u64 P, u64 V, string* sells, u64** pos, u64 i = 0)
{
    if(i == V) {
        printf("-------\n");
    
        for(int v=0; v<V; v++) {
            for(int p=1; p<=P; p++)
            {
                printf("%lu ", split(pos[v][p-1], pos[v][p], sells[v]));
            }
            printf("\n");
        }

        return true;
    }

    for(u64 p=1; p<=P; p++)
    {
        for(u64 j = pos[i][p-1]+1; j<pos[i][p+1]; j++)
        {
            pos[i][p] = j;
            solve(P, V, sells, pos, i+1);
        }
    }

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
            pos[i] = new u64[N+1];
    
            pos[i][0] = 0;
            for(int j=1; j<N; j++)
                pos[i][j] = pos[i][j-1] + 1;
            pos[i][N] = len[i];
        }

        for(int j=0; j<v-1; j++)
        {
            for(int n=0; n<=N; n++)
            {
                printf("%lu ", pos[j][n]);
            }
            printf("\n");
        }
    
        solve(N, v-1, sells, pos);    
        // printf("%s\n", header);

        // for(int i=0; i<v; i++)
        // {
        //     printf("%s %lu\n", names[i], sells[i]);
        // }

        // printf("%lu\n", N-1);

    }
    
    return 0;
}