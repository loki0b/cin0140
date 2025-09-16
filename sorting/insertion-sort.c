#include <stdio.h>

void insertion_sort(int* arr, int n);

int main() {
  int arr[] = {53, 124, 5312, 543, 4321, 67, 7, 2};
  size_t n = sizeof(arr) / sizeof(arr[0]);

  insertion_sort(arr, n);
  for (int i = 0; i < n; i++) printf("%i ", arr[i]);
  putchar('\n');

  return 0;
}

void insertion_sort(int* arr, int n) {
  for (int i = 1; i < n; i++) {
    int v, j;

    v = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > v) {
      arr[j + 1] = arr[j]; // shift-right
      j--;
    }
    arr[j + 1] = v;
  }
}
