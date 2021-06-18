#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

int main() {
    
    u64 max;
    char text[1000000];

    while(scanf("%lu\n", &max) == 1 && max != 0)
    {
        scanf("%[^\n]", text);
        u64 l = strlen(text);
        u64 typed = 0;

        bool used[256];
        bool tmp[256];

        for(int i=0; i<256; i++)
        {
            used[i] = false;
            tmp[i] = false;
        }

        u64 start = 0;
        u64 diff = 0;

        for(int i=0; i<=l; i++)
        {
            char character = text[i];

            if(used[character]) {
                if(i - start > diff)
                    diff = i - start;
            }

            if(!used[character])
            {
                typed++;
                used[character] = true;

                if(typed <= max && i - start > diff)
                    diff = i - start;
            } 

            if(typed > max)
            {
                u64 k = 0;
                u64 j = i;

                while(k < max)
                {
                    if(!tmp[text[j]])
                    {
                        tmp[text[j]] = true;
                        
                        k++;
                        
                        while (tmp[text[j]]){
                            j--;
                        }                
                    } else 
                    {
                        j--;
                    }
                }

                for(int t=0;t<256;t++)
                {
                    used[t] = tmp[t];
                    tmp[t] = false;
                }

                typed = max;
                start = j;

                if(i - start > diff)
                    diff = i - start;
            }

        }

        std::cout << diff << std::endl;
    }


    return 0;
}