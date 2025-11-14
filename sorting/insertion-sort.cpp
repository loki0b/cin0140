#include <vector>

using std::vector;

void insertion_sort(vector<int>& arr) {
  int n = arr.size();

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