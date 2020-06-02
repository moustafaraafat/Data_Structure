#include <stdio.h>
#define  ARRAY_SIZE 5

int linear_search(int arr[], int element, int size);

int main(void) {
	int arr[ARRAY_SIZE];
	int i, element, index;
	setbuf(stdout, NULL);
	printf("Enter %d numbers: ", ARRAY_SIZE);
	for(i=0; i<ARRAY_SIZE; i++)
		scanf(" %d", &arr[i]);
	printf("Enter element to search about: ");
	scanf(" %d", &element);
	index = linear_search(arr, element, ARRAY_SIZE);
	printf("Index is: %d", index);
	return 0;
}
int linear_search(int arr[], int element, int size){
	int i;
	for(i=0; i<size; i++)
		if(element==arr[i])
			return i;
	return -1;
}
