#include <stdio.h>

#define FIRST_ELEMENT 0

void quick_sort(int* arr, int l, int r);
int hoare_partition(int* arr, int l, int r);
void swap(int* ap, int* bp);

int main() {
	int n;
	scanf("%i", &n);

	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%i", &arr[i]);
	}
		
	quick_sort(arr, FIRST_ELEMENT, n - 1);
	return 0;
}

void quick_sort(int* arr, int l, int r) {
	if (l < r) {
		int s, k, m;

		s = hoare_partition(arr, l, r);
	
		k = s - l;
		m = r - s;
		printf("%i %i\n", k, m);

		quick_sort(arr, l, s - 1);
		quick_sort(arr, s + 1, r);
	}
}

int hoare_partition(int* arr, int l, int r) {
	int p, i, j;

	p = arr[l];
	i = l;
	j = r + 1;

	do {	
		do {
			i++;
		} while (arr[i] < p && i <= r);

		do {
			j--;
		} while (arr[j] > p);

		swap(&arr[i], &arr[j]);
	} while (i < j);

	swap(&arr[i], &arr[j]);
	swap(&arr[l], &arr[j]);
	

	return j;
}

void swap(int* ap, int* bp) {
	int temp = *ap;
	*ap = *bp;
	*bp = temp;
}
