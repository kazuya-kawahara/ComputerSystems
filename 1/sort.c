#include<stdio.h>

void sort_int_array(int *ary, int ary_size){
	int k = ary_size - 1;
	while(k >= 1){
		for(int i = 1; i <= k; i++){
			if(ary[i-1] > ary[i]){
				int tmp = ary[i];
				ary[i] = ary[i-1];
				ary[i-1] = tmp;
			}
		}
		k--;
	}
}

int main(){
	printf("ary_size?\n");
	int ary_size;
	scanf("%d", &ary_size);
	printf("ary?\n(");
	int ary[ary_size];
	for(int i = 0; i < ary_size; i++){
		scanf("%d", ary[i]);
	}
	printf(")\n");
	sort_int_array(&ary, ary_size);
	printf("(");
	for(int i = 0; i < ary_size; i++){
		printf(" %d", ary[i]);
	}
	printf(")\n");
}