#include <vector>

using std::vector, std::swap;

void quick_sort(vector<int>& A, int l, int r) {
  int s;
  
  if (l < r) {
    s = hoare_partition(A, l, r); // pivot element
    quick_sort(A, l, s - 1);
    quick_sort(A, s + 1, r);
  }
}

int hoare_partition(vector<int>& A, int l, int r) {
  int p, i, j;

  p = A[l];
  i = l;
  j = r + 1;

  do {
    do {
      i++;
    } while (A[i] < p && i < r);

    do {
      j--;
    } while (A[j] > p);
    
    swap(A[i], A[j]);
  } while (i < j);

  swap(A[i], A[j]); // undo last swap when i >= j
  swap(A[l], A[j]);

  return j;
}