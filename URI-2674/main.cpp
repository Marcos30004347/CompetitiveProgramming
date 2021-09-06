#include <iostream>
#include <vector>

using namespace std;

long long int prim[100001];

int main()
{
    fill(prim, prim + 100001 + 1, 1);

    prim[0] = 0;
    prim[1] = 0;

    for(long long i = 2; i <= 100000; i++)
    {
        if (prim[i] && (i * i) <= 100000) 
        {
            for(long long j = i * i; j <= 100000; j += i)
            {
                prim[j] = 0;
            }
        }
    }

    unsigned long long N;
    unsigned long long k;

    int i = 1;
    while(scanf("%llu\n", &N) == 1)
    {
        // printf("%i %llu\n", i++, N);
        bool super = true;

        if(prim[N])
        {
            while(N > 0)
            {

                k = N%10;
                N = N/10;
                // printf("%llu %llu - ", k, prim[k]);
                
                if(k == 0 || !prim[k])
                {
                    printf("Primo\n");
                    super = false;
                    break;
                }
            }

            if(super)
            {
                printf("Super\n");
            }
        }
        else
        {
            printf("Nada\n");
        }
    }


    return 0;
}