#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge_sort(pair<string, int>& array, int left_index, int right_index, size_t array_size);
void merge(pair<string, int>& array, int left_index, int right_index, size_t array_size);

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

  int n, num;
	string name;
	
	cin >> n;
  pair<string, int> list[n];
  
	for (int i = 0; i < n; i ++) {
		cin >> list[i].first;
    cin >> list[i].second;
	}
  
  merge_sort(*list, 0, n - 1, n);

	for (int i = 0; i < n; i++) cout << list[i].first << " " << list[i].second << "\n";

	return 0;
}

void merge_sort(pair<string, int>& array, int left_index, int right_index, size_t array_size) {
  if (left_index < right_index) {
    int middle;

    middle = (left_index + right_index) / 2;
    merge_sort(array, left_index, middle, array_size);
    merge_sort(array, middle + 1, right_index, array_size);
    merge(array, left_index, right_index, array_size);
  }
}

void merge(pair<string, int>& array, int left_index, int right_index, size_t array_size) {
  pair<string, int> tmp_array[array_size];
  int middle, i1, i2;

  for (int i = 0; i < array_size; i++) {
    tmp_array[i] = array[1];
  }

  middle = (left_index + right_index) / 2;
  i1 = left_index;
  i2 = middle + 1;

  for (int curr = left_index; curr <= right_index; curr++) {
    if (i1 == middle + 1) array[curr] = tmp_array[i2++]; 
    else if (i2 > right_index) array[curr] = tmp_array[i1++]; 
    else if (tmp_array[i1] <= tmp_array[i2]) array[curr] = tmp_array[i1++];
    else array[curr] = tmp_array[i2++];
  }
}
