#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector, std::swap;

template <typename k, typename v>
class node {
public:
    k key;
    v value;

    node(k key, v value) {
        this->key = key;
        this->value = value;
    }
};

template <typename k, typename v>
class priority_queue {
private:
    vector<node<k, v>*> heap;
    bool max_heap;

    void heapify_up(int pos) {
        node<k, v>* value;
        bool heap;

        value = this->heap[pos];
        heap = false;
        
        if (max_heap) {
            while (!heap && pos > 0) {
                int parent_pos = (pos - 1) / 2;
                
                if (this->heap[parent_pos]->key < this->heap[pos]->key) { 
                    this->heap[pos] = this->heap[parent_pos];
                    this->heap[parent_pos] = value;
                    pos = parent_pos;
                }
                else heap = true;
            }
        }
        // MIN_HEAP
        else {
            while (!heap && pos > 0) {
            int parent_pos = (pos - 1) / 2;
            
            if (this->heap[parent_pos]->key > this->heap[pos]->key) { 
                this->heap[pos] = this->heap[parent_pos];
                this->heap[parent_pos] = value;
                pos = parent_pos;
            }
            else heap = true;
            }
        }
    }

    void heapify_down(int pos) {
        node<k, v>* value;  // value of the i-th internal node
        bool heap;

        value = this->heap[pos];
        heap = false;

        if (this->max_heap) {
            while (!heap && (pos * 2) + 1 < this->size) {
                int left_child_pos = (2 * pos) + 1;
                int right_child_pos = (2 * pos) + 2;
                int largest_child_pos = (2 * pos) + 1;

                if (right_child_pos < this->size) { // Has two children
                    if (this->heap[left_child_pos]->key < this->heap[right_child_pos]->key) largest_child_pos = right_child_pos; // Find the largest child
                }

                // Is heap if value->key is greater then or equal to the largest child
                if (value->key >= this->heap[largest_child_pos]->key) heap = true;
                else {
                    this->heap[pos] = this->heap[largest_child_pos];
                    pos = largest_child_pos;
                }
            }

            this->heap[pos] = value;
        }
        // MIN_HEAP
        else {
            while (!heap && (pos * 2) + 1 < this->size) {
                int left_child_pos = (2 * pos) + 1;
                int right_child_pos = (2 * pos) + 2;
                int smallest_child_pos = (2 * pos) + 1;

                if (right_child_pos < this->size) { // Has two children
                    if (this->heap[left_child_pos]->key > this->heap[right_child_pos]->key) smallest_child_pos = right_child_pos; // Find the smallest child
                }

                // Is heap if value->key is less then to the smallest child
                if (value->key <= this->heap[smallest_child_pos]->key) heap = true;
                else {
                    this->heap[pos] = this->heap[smallest_child_pos];
                    pos = smallest_child_pos;
                }
            }

            this->heap[pos] = value;
        }
    }
public:
    int size;

    // Top-Down creation O(n log n)
    priority_queue(bool max_heap=true) {
        this->max_heap = max_heap;
        this->size = 0;
    };

    // Bottom-Up creation O(n)
    priority_queue(vector<node<k, v>*>& container, bool max_heap=true) {
        this->max_heap = max_heap;
        this->heap = container;
        this->size = container.size();

        for (int i = (this->size - 1) / 2; i >= 0; i--) {
            heapify_down(i);
        }
    }

    ~priority_queue() {
        for (auto& n : heap) {
            delete n;
            n = nullptr;
        }
        this->heap.clear();
        this->size = 0;
    };

    void insert(k key, v value) {
        node<k, v>* n;

        n = new node(key, value);
        this->heap.push_back(n);
        this->size++;
        
        heapify_up(this->size - 1);
    };

    node<k, v>* find_top() {
        if (this->size == 0) return nullptr;

        return this->heap[0];
    }; 

    node<k, v>* delete_top() {
        if (this->size == 0) return nullptr;

        node<k, v>* root;
        
        root = this->heap[0];
        this->heap[0] = this->heap[this->size - 1];
        this->heap.pop_back();
        this->size--;

        heapify_down(0);

        return root;
    };
    
    void iter() {
        for (int i = 0; i < this->size; i++) cout << this->heap[i]->key << ' ';
    }

    void heap_sort() {
        int n = this->size;

        for (int i = n - 1; i > 0; i--) {
            swap(this->heap[0], this->heap[i]);
            this->size = i;
            heapify_down(0);
        }

        this->size = n;
    }
};


int main() {
    vector<node<int, int>*> nums1 = vector<node<int, int>*>(0);

    for (int i = 0; i < 5; i++) {
        nums1.push_back(new node(i + 1, i + 1));
    }

    priority_queue<int, int>* pq1 = new priority_queue<int, int>(nums1);
    pq1->iter();
    cout << '\n';
    pq1->insert(6, 6);
    pq1->iter();
    cout << '\n';
    pq1->delete_top();
    pq1->iter();
    cout << '\n';

    pq1->heap_sort();
    pq1->iter();

    return 0;
}