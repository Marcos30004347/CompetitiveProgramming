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

i64 seats[1100][1100];

int main() {

    i64 R,C,K;
    i64 d;
    i64 x;
    while(true)
    {

        scanf("%li %li %li\n", &R, &C, &K);

        // std::cout << R << " " << C << " " << K <<"\n";

        if (R == 0 && C == 0 && K == 0) break;
    
        char seat;

        for(i64 i=0; i<R; i++)
        {
            for(i64 j=0; j<C; j++)
            {
            scanf("%c", &seat);
            // std::cout << seat << "";
            if (seat == 'X') seats[i][j] = 0;
            else seats[i][j] = 1;
            }
            // new line
            scanf("%c", &seat);
        //   std::cout <<"\n";
        }

        i64 a = __LONG_MAX__;

        i64 tmp[1010];

        for(i64 i=0; i<R; i++)
        {
            for(i64 j=0; j<C; j++)
            {
                tmp[j] = 0;
            }

            for(i64 j=i; j<R; j++)
            {

                for(i64 l=0; l<C; l++)
                {
                    tmp[l] = tmp[l] + seats[j][l];
                }

                d = 0;
                x = 0;

                for (i64 t=0; t<C; t++)
                {
                    d = d + tmp[t];
                    while((x < t) && (d >= K + tmp[x])) d = d - tmp[x++];
                    if (d >= K) a = min(a, (std::abs(i-j) + 1)*(std::abs(x-t)+1));
                }

            }

        }

        std::cout << a << "\n";
    }

    return 0;
}