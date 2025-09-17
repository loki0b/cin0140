#include <stdio.h>

void insertion_sort(int* arr, int n);
int binary_search(int* arr, int k, size_t n);

int main() {
  int arr[] = {53, 124, 5312, 543, 4321, 67, 7, 2};
  size_t n = sizeof(arr) / sizeof(arr[0]);

  insertion_sort(arr, n);
  for (int i = 0; i < n; i++) printf("%i ", arr[i]);
  putchar('\n');

  printf("K position -> %i\n", binary_search(arr, 67, n));

  return 0;
}

int binary_search(int* arr, int k, size_t n) {
  int l, r, m;
  
  l = 0;
  r = n - 1;
  while (l <= r) {
    m = (l + r) / 2;
    if (k == arr[m]) return m;
    else if (k < arr[m]) r = m - 1;
    else l = m + 1;
  }

  return -1;
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
