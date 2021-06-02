#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

char message[10000];
char crib[10000];

int main() {
    scanf("%s\n", message);
    scanf("%s\n", crib);

    u64 l = strlen(message);
    u64 k = strlen(crib);

    u64 p = 0;
    u64 o = 0;

    while(l - p >= k)
    {
        bool fail = false;
        for(int i=0; i<k; i++)
        {
            if(crib[i] == message[p+i])
            {
                fail = true;
                break;
            }
        }
    
        if(!fail)
            o++;
    
        p++;
    }

    printf("%lu\n", o);

    return 0;
}