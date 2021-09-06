#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

bool is_prime[10000001];

lli factorialEvenFactos(lli p)
{
    lli n, c = 0;

    for(lli i = p; i > 0; i--)
    {
        n = i;

        while(n % 2 == 0)
        {
            c = c + 1;
            n = n / 2;
        }
    }

    return c;
}

int main()
{
    lli A, B;

    scanf("%lli %lli\n", &A, &B);

    if(A == B)
    {
        printf("?\n");
        return 0;
    }

    fill(is_prime, is_prime + 10000001, true);

    is_prime[0] = is_prime[1] = false;

    for(lli i = 2; i < 10000001; i++)
    {
        if (is_prime[i]) 
        {
            for(lli j = i * i; j < 10000001; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    lli n = 0;

    for(lli i = min(A, B); i <= max(A, B); i++)
    {
        if(is_prime[i])
        {
            n = n + 1;
        }
    }

    if(n == 0)
    {
        printf("Bob\n");
        return 0;
    }

    lli k = max(A, B) - min(A, B);

    lli a = factorialEvenFactos(n + k - 1);
    lli b = factorialEvenFactos(n - 1);
    lli c = factorialEvenFactos(k);

    if(a > (b + c)) 
    {
        printf("Bob\n");
    }
    else
    {
        printf("Alice\n");
    }

    return 0;

}