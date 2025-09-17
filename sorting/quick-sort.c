#include <stdio.h>

#define FIRST_ELEMENT 0

void quick_sort(int* arr, int l, int r);
int hoare_partition(int* arr, int l, int r);
void swap(int* ap, int* bp);

int main() {
  int arr[] = {53, 124, 5312, 543, 4321, 67, 7, 2};
  size_t n = sizeof(arr) / sizeof(arr[0]);

  quick_sort(arr, FIRST_ELEMENT, n - 1);
  for (int i = 0; i < n; i++) printf("%i ", arr[i]);
  putchar('\n');

  return 0;
}

void quick_sort(int* arr, int l, int r) {
  int s;
  
  if (l < r) {
    s = hoare_partition(arr, l, r); // pivot element
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
    } while (arr[i] < p && i < r);

    do {
      j--;
    } while (arr[j] > p);
    
    swap(&arr[i], &arr[j]);
  } while (i < j);

  swap(&arr[i], &arr[j]); // undo last swap when i >= j
  swap(&arr[l], &arr[j]);

  return j;
}

void swap(int* ap, int* bp) {
  int temp = *ap;
  *ap = *bp;
  *bp = temp;
}
