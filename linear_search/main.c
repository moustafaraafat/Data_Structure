#include <stdio.h>
#define ARRAY_SIZE 5
int linear_search(const int *arr, int element, int size);
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
	if (index != -1)
		printf("Index is: %d", index);
	else
		printf("It's not there.");

	return 0;
}
int linear_search(const int *arr, int element, int size){
	const int *p = arr;
	for(; p < arr + size; p++)
		if(*p == element)
			return p - arr;
	return -1;
}
