#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Implicant.h"
#include "QuineMcCluskey.h"
void sort(int arr[],int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main(){
	int *arr, num;
	printf("배열의 크기를 입력하세요:");
	scanf_s("%d", &num);
	arr = (int*)malloc(sizeof(int)*num);
	for (int i = 0; i < num; i++)
		scanf_s("%d", &arr[i]);
	sort(arr, num);
	initialize_QuineMcCluskey(arr, num);
	printPI();
	initialize_EPItable();
	print_EPItable();
	searchEPI();
	print_EPItable();
	removeImplicant();
	print_EPItable();
	print_Formula();
}