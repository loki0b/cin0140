#include <stdio.h>
#include <string.h>

#define FIRST_ELEMENT 0

void merge_sort(int* array, int left_index, int right_index, size_t array_size);
void merge(int* array, int left_index, int right_index, size_t array_size);

typedef struct contato {
	char* name;
 	int num;
} person;

void solve() {
	int n, num;
	char name[3];
	person list[n];
	
	scanf("%i", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%s", name);
		scanf("%i", &num);
		list[i].name = strdup(name);
		list[i].num = num;
	}
	
	for (int i = 0; i < n; i++) printf("%s %i", list[i].name, list[i].num);
	putchar('\n');
}

int main() {
	solve();
	return 0;
}

void merge_sort(int* array, int left_index, int right_index, size_t array_size) {
  if (left_index < right_index) {
    int middle;

    middle = (left_index + right_index) / 2;
    merge_sort(array, left_index, middle, array_size);
    merge_sort(array, middle + 1, right_index, array_size);
    merge(array, left_index, right_index, array_size);
  }
}

void merge(int* array, int left_index, int right_index, size_t array_size) {
  int tmp_array[array_size];
  int middle, i1, i2;

  for (int i = 0; i < array_size; i++) tmp_array[i] = array[i];

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
