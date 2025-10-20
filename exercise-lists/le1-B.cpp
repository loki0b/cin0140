#include <iostream>
#include <vector>

using std::cin, std::cout, std::ios_base, std::vector;

class priority_queue {
private:
    void heapify_up(int pos) {
        int value;
        bool heap;

        value = this->heap[pos];
        heap = false;
        
        while (!heap && pos > 0) {
            int parent_pos = (pos - 1) / 2;
            
            if (this->heap[parent_pos] > value) { 
                this->heap[pos] = this->heap[parent_pos];
                this->heap[parent_pos] = value;
                pos = parent_pos;
            }
            else heap = true;
        }
    }

    void heapify_down(int pos) {
        int value;
        bool heap;

        value = this->heap[pos];
        heap = false;

    
        while (!heap && (pos * 2) + 1 < this->size) {
            int left_child_pos = (2 * pos) + 1;
            int right_child_pos = (2 * pos) + 2;
            int smallest_child_pos = left_child_pos;

            if (right_child_pos < this->size) { // Has two children
                if (this->heap[left_child_pos] > this->heap[right_child_pos]) smallest_child_pos = right_child_pos; // Find the smallest child
            }

            if (value <= this->heap[smallest_child_pos]) heap = true;
            else {
                this->heap[pos] = this->heap[smallest_child_pos];
                pos = smallest_child_pos;
            }
        }
        this->heap[pos] = value;
    }
        
public:
    int size;
    vector<long long> heap;

    // Top-Down creation O(n log n)
    priority_queue() {
        this->size = 0;
    };

    void insert(int x) {
        this->heap.push_back(x);
        this->size++;
        
        heapify_up(this->size - 1);
    };

    int find_min() {
        if (this->size == 0) return -1;

        return this->heap[0];
    }; 

    int delete_min() {
        if (this->size == 0) return -1;

        int ret = this->heap[0];
        
        this->heap[0] = this->heap[this->size - 1];
        this->heap.pop_back();
        this->size--;

        heapify_down(0);

        return ret;
    };
};

void solve() {
    long long n, a, health, drinked_potions; 
    priority_queue negative_potions;

    cin >> n; // The number of potions 1 <= n <= 2 * 10^5
    health = 0;
    drinked_potions = 0;
    for (int i = 0; i < n; i++) {
        cin >> a; // a_ith potion
        if (a >= 0) {
            health += a;
            drinked_potions++;
        }
        else if ((health + a) >= 0) {
            health += a;
            negative_potions.insert(a);
        }
        else {
            if (negative_potions.size > 0) {
                int last_potion = negative_potions.find_min();

                if (last_potion < a) {
                    health -= negative_potions.delete_min();
                    health += a;
                    negative_potions.insert(a);
                }
            }
        }
    }

    drinked_potions += negative_potions.size;

    cout << drinked_potions << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}