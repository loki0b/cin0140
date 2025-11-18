#include <vector>

#define FIRST_ELEMENT 0

using std::vector, std::swap;

void heapify_down(vector<int>& heap, int x, int n) {
    bool is_heap = false;

    while (!is_heap && ((2 * x) + 1) < n) {
        int left_child = (2 * x) + 1;
        int right_child = (2 * x) + 2;
        int largest_child = left_child;

        if (right_child < n && heap[right_child] > heap[left_child]) largest_child = right_child;
        
        if (heap[x] >= heap[largest_child]) is_heap = true;
        else {
            swap(heap[x], heap[largest_child]);
            x = largest_child;
        }
    }
}

void heap_sort(vector<int>& heap) {
    int n = heap.size();
    
    for (int i = (n / 2) - 1; i >= 0; i--) heapify_down(heap, i, n);

    for (int i = n - 1; i > 0; i--) {
        swap(heap[FIRST_ELEMENT], heap[i]);
        heapify_down(heap, FIRST_ELEMENT, i);
    }
}