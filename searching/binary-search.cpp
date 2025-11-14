#include <vector>

using std::vector;

int binary_search(vector<int>& A, int k) {
  int n = A.size();
  
  int l = 0;
  int r = n - 1;
  while (l <= r) {
    int m = (l + r) / 2;

    if (k == A[m]) return m;
    else if (k < A[m]) r = m - 1;
    else l = m + 1;
  }

  return -1;
}
