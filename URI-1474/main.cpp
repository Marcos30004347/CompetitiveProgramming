#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

typedef unsigned long long int u64;

void mmul(u64** A, u64** B, u64** C) {

  u64 i,j,t;
  
  for(i=0; i<2; i++) {
  
    for(j=0; j<2; j++) {
      C[i][j] = 0;
      
      for (t=0; t<2; t++)
      {
        if (A[i][t] > 10000000000000) 
        {
          A[i][t] = A[i][t] % 10000000000000;
        }
        
        if (B[t][j] > 10000000000000) 
        {
          B[t][j] = B[t][j] % 10000000000000;
        }
        
        C[i][j] += (A[i][t] * B[t][j]);
      }
    }
  }

  for(i=0; i<2; i++) 
  {
    for(j=0; j<2; j++)
    {
      if (C[i][j] > 10000000000000) 
      {
        C[i][j] = C[i][j] % 10000000000000;
      }
    }
  }

}

u64** mexp(u64** A, u64 e) {
    u64** C;
    u64** B;

    C    = new u64*[2];
    C[0] = new u64[2];
    C[1] = new u64[2];

    C[0][0] = 1;
    C[0][1] = 0;
    C[1][0] = 0;
    C[1][1] = 1;

    while (e > 0) 
    {
        if (e % 2 == 1)
        {
            B    = new u64*[2];
            B[0] = new u64[2];
            B[1] = new u64[2];

            mmul(C, A, B);
    
            delete[] C[0];
            delete[] C[1];
            delete[] C;

            C = B;
        }

        B    = new u64*[2];
        B[0] = new u64[2];
        B[1] = new u64[2];

        mmul(A,A,B);
        
        A = B;

        e = e / 2;
    }

    return C;
}

int main() {
    u64 n, k, l;

    u64** A;
    u64** B;
    u64** C;

    A    = new u64*[2];
    B    = new u64*[2];
    C    = new u64*[2];
    
    A[0] = new u64[2];
    A[1] = new u64[2];

    B[0] = new u64[2];
    B[1] = new u64[2];

    C[0] = new u64[2];
    C[1] = new u64[2];

    while(scanf("%llu %llu %llu\n", &n, &k, &l) == 3) {
        n = n/5;

        A[0][0] = 1;
        A[0][1] = k;

        B[0][0] = 0;
        B[0][1] = l;
        
        B[1][0] = 1;
        B[1][1] = k;

        B = mexp(B, n);
        
        mmul(A, B, C);
        
        printf("%.6lld\n", C[0][0]%10000000000000);
    }

    delete[] A[0];
    delete[] A[1];
    delete[] A;
    delete[] B[0];
    delete[] B[1];
    delete[] B;
    delete[] C[0];
    delete[] C[1];
    delete[] C;

    return 0;
}