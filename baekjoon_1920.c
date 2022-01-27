#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int bin_search( const int arr[], int n, int size ) {
	int front = 0, rear = size - 1, pivot;
	while (1) {
		pivot = (front + rear) / 2;
		if (arr[pivot] == n) return 1;
		if (arr[front] == n) return 1;
		if (arr[rear]  == n) return 1;

		if (arr[pivot] < n) front = pivot+1;
		else rear = pivot-1;
		if (front >= rear) return 0;
	}
}

int cmp(const void *a, const void* b) {
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a < *(int*)b) return -1;
	else return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int m;
	scanf("%d", &m);
	int* arr2 = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &arr2[i]);
	}

	qsort(arr, n, sizeof(int), cmp);

	for (int j = 0; j < m; j++) {
		printf("%d\n", bin_search(arr, arr2[j], n));
	}

	free(arr2);
	free(arr);
}