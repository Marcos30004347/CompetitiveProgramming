#include <iostream>
#include <bitset>
#include <unordered_map>

using namespace std;

typedef long long int lli;

lli tmp[1000010];
lli count;

unordered_map<lli, lli> a;

bitset<17000000> prime;

int main() 
{
    lli T;

    scanf("%lli\n", &T);

    prime.set();
    
    tmp[0] = 1;
    tmp[1] = 2;

    count = 2;

    for (lli i = 4; i < 16000000; i += 2) 
    {
        prime.reset(i);
    }

    for (lli i = 3; count < 1000010 && i <= 16000000; i += 2)
    {
        if (prime[i]) 
        {
            tmp[count++] = i;
            
            for (lli j = i * i; j<= 16000000; j+=i) 
            {
                prime.reset(j);
            }
        }
    }

    for(lli i = 0; i < T; i++) 
    {
        lli N;

        scanf("%lli\n", &N);

        a.clear();

        for(lli j = 0; j < N; j++) 
        {
            lli idx;
            scanf("%lli", &idx);
            a[idx] = 1;
        }

        for(int j = 0; j < count; j++) 
        {
            if (!a[tmp[j]]) 
            {
                printf("%lli\n", tmp[j] - 1);
                break;
            }
        }

    }

    return 0;
}