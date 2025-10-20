#include <iostream>
#include <vector>

using std::cin, std::cout, std::ios_base, std::vector, std::swap;

// implemented with min heap and bottom up creation
class priority_queue {
private:
    void heapify_down(int i) {
        int value = this->heap[i];
        bool heap = false;

        while (!heap && (i * 2) + 1 < this->heap.size()) {
            int left_child_pos = (2 * i) + 1;
            int right_child_pos = (2 * i) + 2;
            int smallest_child_pos = (2 * i) + 1;

            if (right_child_pos < this->heap.size()) { // Has two children
                if (this->heap[left_child_pos] > this->heap[right_child_pos]) smallest_child_pos = right_child_pos; // Find the smallest child
            }

            // Is heap if value->key is less then to the smallest child
            if (value <= this->heap[smallest_child_pos]) heap = true;
            else {
                this->heap[i] = this->heap[smallest_child_pos];
                i = smallest_child_pos;
            }

        }

        this->heap[i] = value;
    }
public:
    vector<int> heap;

    priority_queue(vector<int>& container) {
        this->heap = container;

        for (int i = (this->heap.size() - 1) / 2; i >= 0; i--) heapify_down(i);
    }

    int delete_min() {
        if (this->heap.empty()) return -1;

        int value = this->heap[0];
        
        swap(this->heap[0], this->heap[this->heap.size() - 1]);
        this->heap.pop_back();
        if (!this->heap.empty()) heapify_down(0);

        return value;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, c;

    cin >> t; // the number of test cases
    for (int i = 0; i < t; i++) {
        cin >> n; // the number of planets
        cin >> c; // the cost of the second machine usage

        vector<int> system(n);
        for (int i = 0; i < n; i++) cin >> system[i];

        priority_queue q(system);

        int total_cost = 0;
        int min_planet = q.delete_min();
        int ith_orbit = 1;
        for (int i = 1; i < n; i++) {
            int planet = q.delete_min();
            if (planet == -1) break;
            
            if (min_planet == planet) ith_orbit++;
            else {
                if (c <= ith_orbit) total_cost += c;
                else total_cost += ith_orbit;

                min_planet = planet;
                ith_orbit = 1;
            }
        }
        if (c <= ith_orbit) total_cost += c;
        else total_cost += ith_orbit;


        cout << total_cost << '\n';
    }


    return 0;
}