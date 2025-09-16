#include <stdio.h>

#define FIRST_ELEMENT 0

void merge_sort(int* array, int left_index, int right_index, size_t array_size);
void merge(int* array, int left_index, int right_index, size_t array_size);

int main() {
  int arr[] = {53, 124, 5312, 543, 4321, 67, 7, 2};
  size_t n = sizeof(arr) / sizeof(arr[0]);

  merge_sort(arr, FIRST_ELEMENT, n - 1, n); // right_index = n - 1 -> value of index not the size of array
  for (int i = 0; i < n; i++) printf("%i ", arr[i]);
  putchar('\n');

  return 0;
}

void merge_sort(int* array, int left_index, int right_index, size_t array_size) {
  if (left_index < right_index) {
    int middle;

    middle = (left_index + right_index) / 2;
    merge_sort(array, left_index, middle, array_size);
    merge_sort(array, middle + 1, right_index, array_size);
    merge(array, left_index, right_index, array_size);
  }
}

void merge(int* array, int left_index, int right_index, size_t array_size) {
  int tmp_array[array_size];
  int middle, i1, i2;

  for (int i = 0; i < array_size; i++) tmp_array[i] = array[i];

  middle = (left_index + right_index) / 2;
  i1 = left_index;
  i2 = middle + 1;

  for (int curr = left_index; curr <= right_index; curr++) { // curr to right_index (inclusive)
    if (i1 == middle + 1) array[curr] = tmp_array[i2++]; // if left side is already sorted
    else if (i2 > right_index) array[curr] = tmp_array[i1++];  // if right side is already sorted
    else if (tmp_array[i1] <= tmp_array[i2]) array[curr] = tmp_array[i1++];
    else array[curr] = tmp_array[i2++];
  }
}
