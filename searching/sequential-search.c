#include <stdio.h>

void swap(int* ap, int* bp);
void selection_sort(int* arr, int n);

int main() {
  int arr[] = {53, 124, 5312, 543, 4321, 67, 7, 2};
  size_t n = sizeof(arr) / sizeof(arr[0]);

  selection_sort(arr, n);
  for (int i = 0; i < n; i++) printf("%i ", arr[i]);
  putchar('\n');

  return 0;
}

void selection_sort(int* arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) min = j;
    }
    swap(&arr[i], &arr[min]);
  }
}

void swap(int* ap, int* bp) {
  int temp;

  temp = *ap;
  *ap = *bp;
  *bp = temp;
}
