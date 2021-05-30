#include <iostream>

typedef long unsigned u64;

u64 v[] = {
    10000,
    5000,
    2000,
    1000,
    500,
    200,
    100,
    50,
    25,
    10,
    5,
    1,
};

int main() {
    u64 d[2];
    scanf("%lu.%2lu", &d[0], &d[1]);

    u64 cents = d[0]*100 + d[1];
    int i = 0;

    printf("NOTAS:\n");
    
    while (true){
        i++;
    
        u64 count = cents / v[i-1];
        
        if(i == 7) printf("MOEDAS:\n");

        cents = cents % v[i-1];

        if(i<7)
            printf("%lu nota(s) de R$ %lu.00\n", count, v[i-1]/100);
        else 
            printf("%lu moeda(s) de R$ %lu.%02lu\n", count, v[i-1]/100, v[i-1]%100);

        if(i==12) break;    
    }
    
    return 0;
}