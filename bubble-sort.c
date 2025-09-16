#include <stdio.h>

void swap(int* ap, int* bp);
void bubble_sort(int* arr, int n);

int main() {
  int arr[] = {53, 124, 5312, 543, 4321, 67, 7, 2};
  size_t n = sizeof(arr) / sizeof(arr[0]);

  bubble_sort(arr, n);
  for (int i = 0; i < n; i++) printf("%i ", arr[i]);
  putchar('\n');

  return 0;
}

void bubble_sort(int* arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j + 1] < arr[j]) swap(&arr[j], &arr[j + 1]);
    }
  }
}

void swap(int* ap, int* bp) {
  int temp;

  temp = *ap;
  *ap = *bp;
  *bp = temp;
}
