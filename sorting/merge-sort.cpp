#include <iostream>
#include <vector>

using std::vector;

void merge_sort(vector<int>& A, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    merge_sort(A, l, m);
    merge_sort(A, m + 1, r);
    merge(A, l, r);
  }
}

void merge(vector<int>& A, int l, int r) {
  int n = A.size();

  int tmp_array[n];
  int m, i1, i2;

  for (int i = l; i <= r; i++) tmp_array[i] = A[i];

  m = (l + r) / 2;
  i1 = l;
  i2 = m + 1;

  for (int curr = l; curr <= r; curr++) { // curr to right_index (inclusive)
    if (i1 == m + 1) A[curr] = tmp_array[i2++]; // if left side is already sorted
    else if (i2 > r) A[curr] = tmp_array[i1++];  // if right side is already sorted
    else if (tmp_array[i1] <= tmp_array[i2]) A[curr] = tmp_array[i1++];
    else A[curr] = tmp_array[i2++];
  }
}