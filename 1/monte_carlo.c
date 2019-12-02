#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int monte_carlo(int n, double* pi){
    if(n <= 0){ return -1; }
    else{
        int k = 0;
        srand((unsigned int)time(NULL));
        for(int i = 0; i < n; i++){
            double x = (double)rand() / (double)RAND_MAX;
            double y = (double)rand() / (double)RAND_MAX;
            if(x*x + y*y < 1){ k++; }
        }
        *pi = 4 * (double)k / (double)n;
        return 0;
    }
}

int main(){
    double* pi;
    printf("pi = %f\n", *pi);
    printf("how many samples?\n");
    int n;
    scanf("%d", &n);
    monte_carlo(n, pi);
    if(monte_carlo(n, pi)){printf("error\n");}
    else{printf("pi = %f\n", *pi);}
    return 0;
}
