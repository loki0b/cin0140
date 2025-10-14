#include <iostream>
#include <vector>

#define MIN_ELEMENT 0
#define FIRST_ELEMENT 0
#define LAST_ELEMENT this->size - 1

using std::cin, std::cout, std::ios_base, std::vector, std::swap;


class priority_queue {
private:
    vector<int> heap;    
    
    void heapify_down(int i) {
        bool heap = false;
        int value = this->heap[i];
        
        while (!heap && ((2 * i) + 1) < this->size) {
            int left_child = (2 * i) + 1;
            int right_child = (2 * i) + 2;
            int smallest_child = left_child;

            if (right_child < this->size) {
                if (this->heap[left_child] > this->heap[right_child]) smallest_child = right_child;
            }

            if (value <= this->heap[smallest_child]) heap = true;
            else {
                this->heap[i] = this->heap[smallest_child];
                i = smallest_child;
            }
        }

        this->heap[i] = value;
    }

public:
    int size;
    
    priority_queue(vector<int>& container) {
        this->heap = container;
        this->size = container.size();
        
        for (int i = (LAST_ELEMENT / 2); i >= 0; i--) heapify_down(i);
    }

    int delete_min() {
        int ret = this->heap[MIN_ELEMENT];

        swap(this->heap[MIN_ELEMENT], this->heap[LAST_ELEMENT]);
        this->heap.pop_back();
        this->size--;

        heapify_down(FIRST_ELEMENT);

        return ret;
    }

    int heap_sort() {
        int n = this->size;

        int min = this->heap[MIN_ELEMENT];
        int count = 1;
        for (int i = n - 1; i > 0; i--) {
            swap(this->heap[MIN_ELEMENT], this->heap[i]);
            this->size = i;
            heapify_down(FIRST_ELEMENT);
            if (min == this->heap[MIN_ELEMENT]) count++;
            else {
                if (count == 1) { 
                    this->size = n;
                    return min;
                }
                else {
                    min = this->heap[MIN_ELEMENT];
                    count = 1;
                }
            }
        }
        
        this->size = n;

        if (count == 1) return min;

        return -1;
    }

    void iter() {
        for (int i = 0; i < this->size; i++) cout << this->heap[i] << ' ';
        cout << '\n';
    }
};

int solve() {
    int n;
    
    cin >> n;
    vector<int> nums = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    priority_queue q = priority_queue(nums);
    
    cout << q.heap_sort() << '\n';
    q.iter();

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!solve()) return 0;
    
    return 1;
}