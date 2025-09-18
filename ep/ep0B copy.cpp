#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

void merge_sort(vector<tuple<string, int>>* array, int left_index, int right_index, size_t array_size);
void merge(vector<tuple<string, int>>* array, int left_index, int right_index, size_t array_size);

typedef struct contato {
  string name;
  int num;
} person;


int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

  int n, num;
	string name;
	
	cin >> n;
  vector<person> list(n);
  
	for (int i = 0; i < n; i ++) {
		cin >> name >> num;
    list[i].name = name;
    list[i].num = num;
	}
  
  merge_sort(&list, 0, n - 1, n);

	for (int i = 0; i < n; i++) cout << list[i].name << "" << list[i].num << "\n";

	return 0;
}

void merge_sort(vector<person>* array, int left_index, int right_index, size_t array_size) {
  if (left_index < right_index) {
    int middle;

    middle = (left_index + right_index) / 2;
    merge_sort(array, left_index, middle, array_size);
    merge_sort(array, middle + 1, right_index, array_size);
    merge(array, left_index, right_index, array_size);
  }
}

void merge(vector<person>* array, int left_index, int right_index, size_t array_size) {
  vector<person> tmp_array[array_size];
  int middle, i1, i2;

  for (int i = 0; i < array_size; i++) {
    tmp_array[i] = array[i];
  }

  middle = (left_index + right_index) / 2;
  i1 = left_index;
  i2 = middle + 1;

  for (int curr = left_index; curr <= right_index; curr++) {
    if (i1 == middle + 1) array[curr] = tmp_array[i2++]; 
    else if (i2 > right_index) array[curr] = tmp_array[i1++]; 
    else if (tmp_array[i1]. <= tmp_array[i2].name) array[curr] = tmp_array[i1++];
    else array[curr] = tmp_array[i2++];
  }
}
