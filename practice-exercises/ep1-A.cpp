#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FIRST_ELEMENT 0

using std::cin, std::cout, std::ios_base, std::vector, std::string, std::sort;

int binary_search(vector<string>& dict, string& word);

void solve() {
    int p, q, x, y;
    string word;

    cin >> p; // 0 < p ≤ 75.000 - Quantidade de palavras no dict
    vector<string> dict(p);
    for (int i = 0; i < p; i++) cin >> dict[i];
    sort(dict.begin(), dict.end());

    cin >> q;
    vector<string> words(q);
    for (int i = 0; i < q; i++) cin >> words[i];

    y = 0;
    for (int i = 0; i < q; i++) {
        x = binary_search(dict, words[i]);
        if (x == 0) y++;
    }

    cout << y << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}

int binary_search(vector<string>& dict, string& word) {
    int m, l, r;

    l = FIRST_ELEMENT;
    r = dict.size() - 1;
    while (l <= r) {
        m = (l + r) / 2;
        if (word == dict[m]) return 0;
        else if (word < dict[m]) r = m - 1;
        else l = m + 1;
    }

    return 1;
}