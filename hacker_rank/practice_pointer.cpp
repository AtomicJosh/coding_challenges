
#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    // Complete this function    
    int ma = *a+*b;
    int mb = abs(*a-*b);
    *a = ma;
    *b = mb;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

