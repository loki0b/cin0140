#include <iostream>
#include <vector>

#define FIRST_ELEMENT 0

using std::cin, std::cout, std::ios_base, std::vector;

void merge_sort(vector<int>& arr, int l, int r);
void merge(vector<int>& arr, int l, int r);
int binary_search(vector<int>& arr, int k);

void solve() {
    int n, q, m, arr_n, p;

    cin >> n; // n (1 ≤ n ≤ 100 000) — the number of shops in the city
    vector<int> shops_list(n);
    for (int i = 0; i < n; i++) {
        cin >> shops_list[i]; // n integers xi (1 ≤ xi ≤ 100 000) — prices of the bottles of the drink in the i-th shop
    }

    arr_n = shops_list.size();
    merge_sort(shops_list, FIRST_ELEMENT, arr_n - 1);

    cin >> q; // single integer q (1 ≤ q ≤ 100 000) — the number of days
    for (int i = 0; i < q; i++) {
        cin >> m; // q lines each containing one integer mi (1 ≤ mi ≤ 109) — the number of coins Vasiliy can spent on the i-th day
        p = binary_search(shops_list, m);
        cout << p + 1 << '\n';
    } 
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void merge_sort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m;

        m = (l + r) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, r);
    }
}

void merge(vector<int>& arr, int l, int r) {
    int m, n, i1, i2;
  
    n = arr.size();
    vector<int> tmp_arr(n);
    
    for (int i = l; i < r + 1; i++) tmp_arr[i] = arr[i];

    m = (l + r) / 2;
    i1 = l;
    i2 = m + 1;

    for (int curr = l; curr <= r; curr++) {
        if (i1 == m + 1) arr[curr] = tmp_arr[i2++];
        else if (i2 > r) arr[curr] = tmp_arr[i1++];
        else if (tmp_arr[i1] <= tmp_arr[i2]) arr[curr] = tmp_arr[i1++];
        else arr[curr] = tmp_arr[i2++];
    }
}

int binary_search(vector<int>& arr, int k) {
    int l, r, m, ret;

    l = FIRST_ELEMENT;
    r = arr.size() - 1;
    ret = -1;
    while (l <= r) {
        m = (l + r) / 2;

        if (arr[m] <= k) { 
          ret = m;
          l = m + 1;
        }
        else r = m - 1;
    }

    return ret;
}
