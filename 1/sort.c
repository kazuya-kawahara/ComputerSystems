#include<stdio.h>

void swap(int* x, int* y){
	int tmp = *y;
	*y = *x;
	*x = tmp;
}

void sort_int_array(int* ary, int ary_size){
	int k = ary_size - 1;
	while(k > 0){
		for(int i = 0; i < k; i++){
			if(*(ary+i) > *(ary+i+1)){
				swap(ary+i,ary+i+1);
			}
		}
		k--;
	}
}

int main(){
	printf("ary_size?\n");
	int ary_size;
	scanf("%d", &ary_size);
	
	int ary[ary_size];
	printf("ary?\n");
	for(int i = 0; i < ary_size; i++){
		scanf("%d", ary+i);
	}

	sort_int_array(ary, ary_size);
	for(int i = 0; i < ary_size; i++){
		printf("%d ", *(ary+i));
	}
	printf("\n");
	return 0;
}