#include <vector>

using std::vector;

int sequential_search(vector<int>& A, int k) {
  int n = A.size();
  int i = 0;

  for (int i = 0; i < n; i++) if (A[i] == k) return i;
  
  return -1;
}

int sorted_sequential_search(vector<int>& A, int k) {
  int n = A.size();
  int i = 0;

  for (int i = 0; i < n && A[i] <= k; i++) if (A[i] == k) return i;

  return -1;
}
