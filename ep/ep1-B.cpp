#include <iostream>
#include <vector>
#include <algorithm>

#define FIRST_ELEMENT 0

using std::cin, std::cout, std::ios_base, std::vector, std::sort;

int binary_search(vector<int>& list, int& num);

void solve() {
    int n, q, x, y;

    cin >> n; // 0 < n ≤ 500.000 - Quantidade de números na lista
    vector<int> list(n);
    for (int i = 0; i < n; i++) cin >> list[i];
    sort(list.begin(), list.end());
    
    cin >> q; // 0 < q ≤ 500.000 - Quantidade de perguntas
    for (int i = 0; i < q; i++) {
        cin >> x;
        y = binary_search(list, x);
        
        if (x == list[y]) cout << x << '\n';
        else if ((x - list[y - 1]) < (list[y] - x)) cout << list[y - 1] << '\n';
        else cout << list[y] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

int binary_search(vector<int>& list, int& num) {
    int m, l, r;

    l = FIRST_ELEMENT;
    r = list.size() - 1;
    while (l <= r) {
        m = (l + r) / 2;

        if (num == list[m]) return m;
        else if (num < list[m]) r = m - 1;
        else l = m + 1;
    }

    return r;    
}
