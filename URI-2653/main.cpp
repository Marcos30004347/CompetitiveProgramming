#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

char l[1000000];

int main() {
    std::set<std::string> s;

    while(scanf("%s\n", l) == 1)
        s.insert(std::string(l));

    printf("%lu\n", s.size());

    return 0;
}