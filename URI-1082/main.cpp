#include <iostream>
#include <algorithm>

typedef long unsigned u64;

void dfs(bool* G, bool* V, char* C, u64* s, int c) {
    if(V[c]) return;

    V[c] = true;

    C[*s] = 'a' + c;
    *s = *s + 1;

    for(int i=0; i<26; i++) {
        if(G[c*26 + i]) {
            dfs(G, V, C, s, i);
        }
    }
}

int main() {
    u64 N;

    scanf("%lu", &N);

    u64 c = N;

    while(N) {
        printf("Case #%li:\n", c - --N);

        bool G[26*26] = { false };
        bool R[26] = { false };

        u64 V, E;
      
        scanf("%lu %lu\n", &V, &E);
      
        char a,b;
        for(int e=0; e<E; e++) {
            scanf("%c %c\n", &a, &b);
            G[(a - 'a')*26 + (b - 'a')] = true;
            G[(b - 'a')*26 + (a - 'a')] = true;
        }
        
        u64 S = 0;
        u64 L = 0;
        u64 v = 0;
        
        while(true) {
            L++;

            u64 s = 0;
            char C[26] = { '\0' };

            dfs(G, R, C, &s, v);

            S += s;
        
            std::sort(C, C+s);
        
            for(int i=0; i<s; i++)
                printf("%c,", C[i]);
            printf("\n");

            for(int i=0; i<V; i++) {
                if(!R[i]) { 
                    v = i;
                    break;
                }
            }

            if(S == V) break;
        }

        printf("%lu connected components\n\n", L);
    }

    return 0;
}