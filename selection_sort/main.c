#include <stdio.h>
#define ARRAY_SIZE 6
void selection_sort(int *a, int n);
int main(void) {
	int a[ARRAY_SIZE], i;
	setbuf(stdout, NULL);
	printf("Enter %d numbers to be sorted: ", ARRAY_SIZE);
	for (i = 0; i < ARRAY_SIZE; i++)
		scanf("%d", &a[i]);

	selection_sort(a,ARRAY_SIZE);

	printf("In sorted order: ");
	for (i = 0; i < ARRAY_SIZE; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
void selection_sort(int *a, int n){
	int i,j, min_index, temp;
	for(i=0; i< n; i++){
		min_index=i;
		for(j=i+1; j<n; j++){
			if(a[j]<a[min_index]){
				min_index = j;
			}
		}
		if(min_index!=i){
			temp = a[i];
			a[i]=a[min_index];
			a[min_index]=temp;
		}
	}
}
