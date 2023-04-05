//Author -> fatzzx
//Exercise -> 3058
//OBI
#include <stdio.h>

int main (){

    int n, ini, f, contador =0, soma;
    scanf("%d %d %d", &n, &ini, &f);
    int v[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            soma = v[i] + v[j]; 
            if(soma >= ini && soma <= f ){
                contador++;
            }
        }
    }
    printf("%d\n", contador);
    
    return 0;
}