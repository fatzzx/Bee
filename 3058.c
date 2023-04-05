#include <stdio.h>

int main (){
    int n;
    scanf("%d", &n);
    int g[n];
    float p[n], div, result;
    scanf("%f %d", &p[0], &g[0]);
    result = p[0]/g[0];
    for(int i = 1; i < n;i++){
        scanf("%f %d", &p[i], &g[i]);
        div = p[i]/ g[i];
        if (div < result){
            result = div;
        }
    }
    result = result * 1000;
    printf("%.2f\n", result);
    


    return 0;
}