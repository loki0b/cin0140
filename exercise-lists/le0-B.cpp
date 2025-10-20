#include <iostream>
#include <vector>

#define FIRST_ELEMENT 0

using std::cin, std::cout, std::ios_base, std::vector;

void quick_sort(vector<int>& arr, int l, int r);
int hoare_partition(vector<int>& arr, int l, int r);
void swap(int* ap, int* bp);

void solve() {
  int t, n, ai, sum, m;

  cin >> t; // 1 ≤ t ≤ 5000 - the number of test cases
  for (int i = 0; i < t; i++) {
    cin >> n; // 1 ≤ n ≤ 50 - the number of integers written on the whiteboard is 2n
    n *= 2;
    
    vector<int> num_list(n);
    for (int j = 0; j < n; j++) cin >> num_list[j];
    
    quick_sort(num_list, FIRST_ELEMENT, n - 1);

    sum = 0;
    for (int k = 0; k < n; k += 2) sum += num_list[k];

    cout << sum << '\n';
  }
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}

void quick_sort(vector<int>& arr, int l, int r) {
  int s;

  if (l < r) {
    s = hoare_partition(arr, l, r);
    quick_sort(arr, l, s - 1);
    quick_sort(arr, s + 1, r);
  }
}

int hoare_partition(vector<int>& arr, int l, int r) {
  int p, i, j;

  p = arr[l];
  i = l;
  j = r + 1;

  do {
    do {
      i++;
    } while (arr[i] < p && i < r);

    do {
      j--;
    } while (arr[j] > p);
    
    swap(&arr[i], &arr[j]);
  } while (i < j);

  swap(&arr[i], &arr[j]); // undo last swap when i >= j
  swap(&arr[l], &arr[j]);

  return j;
}

void swap(int* ap, int* bp) {
  int temp = *ap;
  *ap = *bp;
  *bp = temp;
}