#include <iostream>
#include <vector>

using std::cin, std::cout, std::vector;

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

    void heapify_up(int pos) {
        node<k, v>* value;
        bool heap;

        value = this->heap[pos];
        heap = false;

        while (!heap) {
            int parent_pos = (pos - 1) / 2;
            
            if (this->heap[parent_pos]->key < this->heap[pos]->key) { 
                this->heap[pos] = this->heap[parent_pos];
                this->heap[parent_pos] = value;
                pos = parent_pos;
            }
            else heap = true;
        }
    }

    void heapify_down(int pos) {
        node<k, v>* value;  // value of the i-th internal node
        bool heap;

        value = this->heap[pos];
        heap = false;

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
public:
    int size;

    // Top-Down creation O(n log n)
    priority_queue() {
        this->size = 0;
    };

    // Bottom-Up creation O(n)
    priority_queue(vector<node<k, v>*>& container) {
        this->heap = container;
        this->size = container.size();

        for (int i = (this->size - 1) / 2; i >= 0; i--) {
            heapify_down(i);
        }
    }

    ~priority_queue() {};

    void insert(k key, v value) {
        node<k, v>* n;

        n = new node(key, value);
        this->heap.push_back(n);
        heapify_up(this->size);
        this->size++;
    };

    node<k, v>* find_max() {
        if (this->size == 0) return nullptr;

        return this->heap[0];
    };

    node<k, v>* delete_max() {
        if (this->size == 0) return nullptr;

        node<k, v>* root;
        
        root = this->heap[0];
        this->heap[0] = this->heap[this->size - 1];
        this->size--;

        heapify_down(0);

        return root;
    };
};


int main() {
    vector<node<int, int>*> nums = vector<node<int, int>*>(0);

    for (int i = 0; i < 5; i++) {
        nums.push_back(new node(i + 1, i + 1));
    }

    priority_queue<int, int>* pq = new priority_queue<int, int>(nums);
    
    cout << pq->find_max()->key << '\n';
    pq->insert(8, 8);
    cout << pq->find_max()->key << '\n';

    node<int, int>* n = pq->delete_max();
    n = pq->delete_max();
    cout << pq->find_max()->key << '\n';

    return 0;
}