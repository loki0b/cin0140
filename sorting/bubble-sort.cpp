#include <vector>

using std::vector;

void bubble_sort(vector<int>& arr) {
  int n = arr.size();

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j + 1] < arr[j]) swap(&arr[j], &arr[j + 1]);
    }
  }
}

void swap(int* ap, int* bp) {
  int temp;

  temp = *ap;
  *ap = *bp;
  *bp = temp;
}
