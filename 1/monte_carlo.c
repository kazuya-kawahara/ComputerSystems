#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int monte_carlo(int n, double* pi){
    if(n <= 0){ return 0; }
    else{
        int k = 0;
        double x,y;
        srand((unsigned int)time(NULL));
        for(int i = 0; i < n; i++){
            x = (double)rand() / (double)RAND_MAX;
            y = (double)rand() / (double)RAND_MAX;
            if(x*x + y*y < 1){ k++; }
        }
        *pi = 4 * (double)k / (double)n;
        return 1;
    }
}

int main(){
    double pi;
    printf("pi = %f\n", pi);
    printf("how many samples?\n");
    int n;
    scanf("%d", &n);
    int result = monte_carlo(n, &pi);
    if(result){printf("pi = %f\n", pi);}
    else{printf("error\n");}
    return 0;
}
