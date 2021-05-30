#include <iostream>
#include <algorithm>

typedef long unsigned u64;
typedef long i64;

void postfix(char* infix, char* prefix, int ii, int ij, int pi, int pj) {
    if(pi > pj || ii > ij)
        return;

    char root = infix[ii]; // = A

    int p = pi;

    while(prefix[p] != root && p != ij) {
        p++;
    }

    i64 l = p - pi;
    i64 r = pj - p;

    postfix(infix, prefix, ii+1, ii+l, pi, pi+l-1);
    postfix(infix, prefix, ii+l+1, ij, pj-r+1, pj);

    printf("%c", root);

    return;
}

int main() {
    i64 t;
    scanf("%li\n", &t);
    while(t--) {
        i64 c;
        
        scanf("%li ", &c);
        
        char infix[52]  = {'\0'};
        char prefix[52] = {'\0'};

        for(int i=0; i<c; i++)
            scanf("%c", &infix[i]);
        for(int i=0; i<c; i++)
            scanf(" %c\n", &prefix[i]);

        postfix(infix, prefix, 0, c-1, 0, c-1);
        printf("\n");
    }
    return 0;
}