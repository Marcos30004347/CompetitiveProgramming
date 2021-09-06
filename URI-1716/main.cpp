#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int gcdExtended(int a, int b, int *x, int *y)  
{  

  if (a == 0) 
  {
    *x = 0, *y = 1;  
    return b;  
  }  

  int x1, y1; 
  
  int gcd = gcdExtended(b%a, a, &x1, &y1);  

  *x = y1 - (b/a) * x1;  
  *y = x1;  

  return gcd;
}

int modInverse(int a, int m)  
{  
  int x, y;  
  int g = gcdExtended(a, m, &x, &y);  
  if (g != 1) 
    return -1;  
  else 
  {
    int res = (x%m + m) % m;  
    return res;
  }
}

int main()
{
    unsigned long long int N, E, C, P, Q, phi, D, M, H, i, k;

    scanf("%llu %llu %llu\n", &N, &E, &C);

    H = ceil(sqrt(N)) + 10;

    bool* is_prime = new bool[H + 1];

    fill(is_prime, is_prime + H + 1, true);

    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= N; i++) 
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= H; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for(P = 2; P <= H; P++)
    {
        if(is_prime[P] && N % P == 0)  break;
    }

    delete[] is_prime;

    Q = N/P;

    phi = (P - 1)*(Q - 1);

    D = modInverse(E, phi);
    
    M = C;

    k = 1;

    while(D > 1)
    {
        if(D%2 == 0)
        {
            C = (C * C) % N;
            D = D/2;
        }
        else
        {
            k = (C * k) % N;
            C = (C * C) % N;
            D = (D-1)/2;
        }
    }

    std::cout << (C*k)%N << "\n";
 
 
    return 0;
}