#include <bits/stdc++.h>

using namespace std;

typedef double f64;
typedef long long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

int main(){
    u64 n, k;

    std::set<int> divisores;

    scanf("%llu\n", &n);

    k = n;

    for(u64 i=2; (i*i)<=n;){
        if(k%i == 0){
            k = k/i;
            divisores.insert(i);
        } else {
            i++;
        }
    }

    if(k!=1){
        divisores.insert(k);
    }

    u64 x = divisores.size();
    u64 despojados = (u64)(pow(2, x)  - x - 1);
    
    printf("%llu\n", despojados);

    return 0;
}