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

const char* braile[10][3] = {
    // 0
    {
        ".*",
        "**",
        "..",
    },
    // 1
    {
        "*.",
        "..",
        "..",
    },
    // 2
    {
        "*.",
        "*.",
        "..",
    },
    // 3
    {
        "**",
        "..",
        "..",
    },
    // 4
    {
        "**",
        ".*",
        "..",
    },
    // 5
    {
        "*.",
        ".*",
        "..",
    },
    // 6
    {
        "**",
        "*.",
        "..",
    },
    // 7
    {
        "**",
        "**",
        "..",
    },
    // 8
    {
        "*.",
        "**",
        "..",
    },
    // 9
    {
        ".*",
        "*.",
        "..",
    },
};

int main() {
    u64 D;
    char C;
    while (scanf("%lu\n", &D) == 1)
    {
        if(D == 0)
            break;

        scanf("%c\n", &C);

        if(C == 'S')
        {
            vector<i64> values;
            for(int i=0; i<D; i++)
            {
                char n;
                scanf("%c", &n);
                values.push_back(n - '0');
            }
            for(int i=0; i<D; i++)
            {
                printf("%s", braile[values[i]][0]);
                if(i!=D-1)
                    printf(" ");
            }
            printf("\n");
            for(int i=0; i<D; i++)
            {
                printf("%s", braile[values[i]][1]);
                if(i!=D-1)
                    printf(" ");
            }
            printf("\n");
            for(int i=0; i<D; i++)
            {
                printf("%s", braile[values[i]][2]);
                if(i!=D-1)
                    printf(" ");
            }

            printf("\n");
        }

        if(C == 'B')
        {
            char l[D][3][2] = {'\0'};

            for(int i=0; i<D; i++)
                scanf("%c%c ", &l[i][0][0], &l[i][0][1]);
            scanf("\n");
            for(int i=0; i<D; i++)
                scanf("%c%c ", &l[i][1][0], &l[i][1][1]);
            scanf("\n");
            for(int i=0; i<D; i++)
                scanf("%c%c ", &l[i][2][0], &l[i][2][1]);
            scanf("\n");
        
            for(int k=0; k<D; k++)
            {
                for(int i=0; i<10; i++)
                {
                    if(
                        l[k][0][0] == braile[i][0][0] && l[k][0][1] == braile[i][0][1] &&
                        l[k][1][0] == braile[i][1][0] && l[k][1][1] == braile[i][1][1] &&
                        l[k][2][0] == braile[i][2][0] && l[k][2][1] == braile[i][2][1]
                    ) {
                        printf("%i", i);
                        break;
                    }
                }
            }

            printf("\n");
        }
        scanf(" \n");
    }
    
    return 0;
}