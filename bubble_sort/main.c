#include <stdio.h>
#define ARRAY_SIZE 6
void print_array(int *a, int n);

void bubble_sort(int *a, int n);
int main(void) {
	int a[ARRAY_SIZE], i;
	setbuf(stdout, NULL);
	printf("Enter %d numbers to be sorted: ", ARRAY_SIZE);
	for (i = 0; i < ARRAY_SIZE; i++)
		scanf("%d", &a[i]);

	bubble_sort(a, ARRAY_SIZE);

	printf("In sorted order: ");
	for (i = 0; i < ARRAY_SIZE; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
void bubble_sort(int *a, int n){
	int i,j, temp, flag;
	for(i=0; i< n-1; i++){
		flag=0;  // flag is to make sure that it's not sorted already
		for(j=0; j< n-i-1; j++){
			if(a[j]>a[j+1]){
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
				flag = 1;
			}
			print_array(a, n);
		}
		if (flag==0)
			break;
	}
}
void print_array(int *a, int n){
	int i;
	printf("Check order: ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	return ;
}
