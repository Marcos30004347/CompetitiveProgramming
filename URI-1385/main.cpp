#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <string>
#include <string.h>

using namespace std;

typedef double f64;
typedef long unsigned u64;
typedef long i64;

#define INF 0xf3f3f3f3

i64 split(u64 f, u64 t, string n)
{
    if(n[f] == '0' && atoll(n.substr(f, t-f).c_str()) != 0)
        return INF;
    
    return atoll(n.substr(f, t-f).c_str());
}

bool solve(u64 N, u64 V, u64 l, u64 r, u64 i, string* names, string* sells, u64** pos, u64 k) {
    if(i == V)
    {

        u64 vals[N+1];

        for(int j=0; j<=N; j++)
            vals[j] = 0;

        for(int v=0; v<V; v++)
        {
            for(int s=1; s<=N; s++)
            {
                if(s < N && split(pos[v][s-1], pos[v][s], sells[v]) >= 1000)
                {
                    return false;
                }
                
                vals[s] += split(pos[v][s-1], pos[v][s], sells[v]);
            }
        }
        string total = sells[V];
        
        for(int s=1; s<=N; s++)
        {
            bool found = false;

            for(int j=0; j<=total.length(); j++)
            {
                if(split(0, j, total) == vals[s])
                {
                    total = total.substr(j, total.length());
                    found = true;

                    break;
                }
            }

            if(found == false)
            {
                break;
            }

            if(s == N && found)
            {
                for(u64 i=1; i<N; i++)
                {
                    printf("P%lu ", i);
                }
                printf("Totals\n");
                for(int v=0; v<V; v++)
                {
                    printf("%s ", names[v].c_str());
                    for(int s=1; s<=N; s++)
                    {
                        printf("%lu ", split(pos[v][s-1], pos[v][s], sells[v]));
                    }
                    printf("\n");
                }
                printf("TP ");

                for(int s=1; s<=N; s++)
                {
                    printf("%lu ",  vals[s]);
                }
                printf("\n");
                return true;
            }
        }
    
        return false;
    }


    if(k == 0)
    {
        return solve(N, V, pos[i+1][N-1], pos[i+1][N], i+1, names, sells, pos, N-1);
    }


    u64 old_left = pos[i][k-1];
    u64 old_rigth = pos[i][k];
    
    for(u64 right = l; right < r; right++)
    {
        pos[i][k-1] = old_left;
        pos[i][k]   = right;

        if(solve(N, V, pos[i][k-1], pos[i][k], i, names, sells, pos, k-1))
            return true;
    }

    pos[i][k-1] = old_left;
    pos[i][k]   = old_rigth;
    return false;
}

bool relatorio(u64 cum, u64 seller, u64 sellers_count, u64 product, u64 product_count, u64* pos, string* sells, string* names, u64** relat)
{
    if(product >= product_count)
    {
        u64 total_idx = seller;
        string total = sells[total_idx];
        for(int i=0; i<sellers_count; i++)
        {
            u64 val = 0;
            for(int j=0; j<product_count; j++)
            {
                val+= relat[i][j];
            }

            if(val != split(0, sells[i].length(), sells[i]))
                return false;
        }

        for(u64 i=1; i<=product_count; i++)
            printf("P%lu ", i);
        printf("Totals\n");
        u64 bottom[product_count];

        for(int i=0; i<product_count; i++)
            bottom[i] = 0;

        u64 total_sum = 0;

        for(int i=0; i<sellers_count; i++)
        {
            printf("%s ", names[i].c_str());
            for(int j=0; j<product_count; j++)
            {
                bottom[j] += relat[i][j];
                printf("%lu ", relat[i][j]);
            }
            printf("%s\n", sells[i].c_str());
        }

        printf("TP ");
        for(int j=0; j<product_count; j++)
        {
            total_sum += bottom[j];
            printf("%lu ", bottom[j]);
        }
        printf("%lu\n", total_sum);
        return true;
    }
    else if(seller >= sellers_count)
    {
        string total = sells[seller];
        for(u64 i=1; i<std::min((std::size_t)5, total.length()); i++)
        {

            if(cum == split(0, i, total))
            {
                for(int i=0; i<sellers_count; i++)
                    relat[i][product] = split(0, pos[i], sells[i]);

                relat[sellers_count][product] = cum;

                string tmp_sells[sellers_count+1];
                u64 tmp_pos[sellers_count];
                
                for(int t=0; t<sellers_count; t++)
                {
                    tmp_sells[t] = sells[t].substr(pos[t], sells[t].length());
                    tmp_pos[t] = 0;
                }

                tmp_sells[sellers_count] = total.substr(i, total.length());

                if(relatorio(0, 0, sellers_count, product + 1, product_count, tmp_pos, tmp_sells, names, relat))
                    return true;
            }        
        }

        return false;
    }
    else
    {

        for(u64 i=1; i<std::min((std::size_t)4, sells[seller].length()); i++)
        {

            // std::cout << "sells: " << sells[seller] << std::endl;
            // if(sells[seller][i] == '0' && split(0, i, sells[seller]) != 0)
            //     continue;
            // while(sells[seller][i] == '0' && split(0, i, sells[seller]) != 0) {
            //     i++;
            // }

            pos[seller] = i;

            if(relatorio(
                cum + split(0, i, sells[seller]),
                seller + 1,
                sellers_count,
                product,
                product_count,
                pos,
                sells,
                names,
                relat
            )) return true;
        }

    }

    return false;
}

int main() {
    u64 C;
    scanf("%li\n", &C);
    while(C--)
    {
        char header[17];
        scanf("%s\n", header);
        
        u64 N = (strlen(header) - 6)/2;

        string names[5];
        string sells[5];

        u64 len[5];

        u64 v = 0;

        char tmp[60];
        char name[60];
        char sell[60];
        do 
        {
            scanf("%s\n", tmp);
            sscanf(tmp, "%[a-zA-Z]%[0-9]", name, sell);
    
            names[v] = name;
            sells[v] = sell;
            len[v] = strlen(tmp) - names[v].length();
        } while(names[v++] != "TP");


        u64* pos = new u64[5];

        for(int i=0; i<5; i++)
            pos[i] = 0;
        
        u64** rel = new u64*[v];
        for(int i=0; i<v; i++)
            rel[i] = new u64[N+1];

        relatorio(0, 0, v-1, 0, N, pos, sells, names, rel);

    }
    
    return 0;
}