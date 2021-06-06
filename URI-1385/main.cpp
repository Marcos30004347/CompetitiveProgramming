#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

u64 split(u64 f, u64 t, u64 n)
{
    u64 k = n % (u64)pow(10,f);
    return k/(u64)pow(10, t);
}

int main() {
    u64 C;
    scanf("%li\n", &C);
    while(C--)
    {
        char header[17];
        scanf("%s\n", header);
        
        u64 N = (strlen(header) - 6)/2;

        char names[5][11];
        u64 vendas[5];
        u64 len[5];

        u64 v = 0;

        do 
        {
            scanf("%[a-zA-Z]%lu\n", names[v], &vendas[v]);
            len[v] = 1 + (u64)log10(vendas[v]);
        } while(strcmp(names[v++], "TP") != 0);
    
    
        printf("%s\n", header);

        for(int i=0; i<v; i++)
        {
            printf("%s %lu\n", names[i], vendas[i]);
        }
        printf("%lu\n", split(2, 0, vendas[0]));
    }
    
    return 0;
}