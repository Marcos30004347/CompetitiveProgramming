#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

bool dobra(vector<u64> in, vector<u64> out)
{
    if(in.size() < out.size())
        return false;

    std::vector<u64> tape;

    for(i64 p=0; p<=in.size(); p++)
    {
        tape.clear();
    
        i64 l = p;
        i64 r = in.size() - p;

        for(int i=0; i<r-l; i++)
            tape.push_back(in[in.size() - i - 1]);

        for(int i=0; i<l-r; i++)
            tape.push_back(in[i]);

        for(int i=0; i<std::min(p, r); i++)
            tape.push_back(
                in[p + std::min(p, r) - 1 - i] +
                in[p - std::min(p, r) + i]
            );

        if(tape.size() == out.size())
        {
            bool match = true;
            
            for(int i=0; i<tape.size(); i++)
                if(tape[i] != out[i])
                {
                    match = false;
                    break;
                }
            
            if(match) return true;
        }

        if(tape.size() != in.size() && dobra(tape, out))
            return true;
    }

    return false;
}

int main() {
    u64 N;
    while(scanf("%lu\n", &N) == 1)
    {
        vector<u64> input = vector<u64>(N);

        for(i64 i=0; i<N; i++)
            scanf("%lu", &input[i]);

        scanf("%lu\n", &N);

        vector<u64> output = vector<u64>(N);

        for(i64 i=0; i<N; i++)
            scanf("%lu", &output[i]);
    
        if(dobra(input, output))
            std::cout << "S" << std::endl;
        else
            std::cout << "N" << std::endl;
    }

    return 0;
}