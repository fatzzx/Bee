//Author -> fatzzx
//Exercise -> 2424
//OBI

#include <stdio.h>

int main(){

    int x, y;

    while(scanf("%d %d", &x, &y) != EOF){
        if(x >= 0 && x <= 432 && y >= 0 && y <= 468){
            printf("dentro\n");
        } else {
            printf("fora\n");
        }
    }



    return 0;
}