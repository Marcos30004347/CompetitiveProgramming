#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <string>
#include <tuple>
#include <set>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

char str[100000];

int mod(const char* num, int a)
{
    int r = 0;
    
    for (int i = 0; i < strlen(num); i++)
        r = (r * 10 + (int)num[i] - '0') % a;
    
    return r;
}

int main() {
    scanf("%s\n", str);
    std::cout << mod(str, 3) << std::endl;
    return 0;
}