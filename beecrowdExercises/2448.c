//bitewise
#include <stdio.h>

int main(){

    int x;
    scanf("%d", &x);
    if((x>>1)<<1 == x){
        printf("par\n");
    }
    else{
        printf("impar\n");
    }

    return 0;
}

