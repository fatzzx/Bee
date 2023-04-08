//Author -> fatzzx
//Exercise -> 3060
//OBI
#include <stdio.h>

int main(){

    int v, p;

    scanf("%d %d", &v, &p);

    if (v % p == 0){
        int d = v / p;
        for (int i = 0; i < p; ++i){
            printf("%d\n", d);
        }
    }
    else{

        int r = v % p;
        int d = v / p;
        for (int i = 0; i < r; ++i){
            printf("%d\n", d + 1);
        }

        for (int i = 0; i < p - r; ++i){
            printf("%d\n", d);
        }
            
    }
    
    return 0;

}