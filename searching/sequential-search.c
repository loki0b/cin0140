int sequential_search(int* array, int k, size_t n) {
  int i = 0;
  while (i < n) {
    if (array[i] == k) return i;
    i++;
  }

  return -1;
}

// Array need to be sorted
int improved_sequential_search(int* array, int k, size_t n) {
  int i = 0;
  while (i < n && array[i] <= k) {
    if (array[i] == k) return i;
    i++;
  }

  return -1;
}
