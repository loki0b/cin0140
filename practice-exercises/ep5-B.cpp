#include <iostream>
#include <vector>
#include <algorithm>
    
using std::cin, std::cout, std::vector, std::min, std::ios;
    
void solve() {
    int n;
    cin >> n;
    
    vector<vector<long long>> dist(n, vector<long long>(n));
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> dist[i][j];
    
    int k;
    cin >> k;
    
    vector<long long> results;
    
    for (int step = 0; step < k; ++step) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        --a; --b;
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                long long new_dist = std::min(
                    dist[i][a] + c + dist[b][j],
                    dist[i][b] + c + dist[a][j]
                );
                if (new_dist < dist[i][j]) {
                    dist[i][j] = new_dist;
                }
            }
        }
    
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                total += dist[i][j];
            }
        }
    
        results.push_back(total);
    }
    
    for (size_t i = 0; i < results.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << results[i];
    }
    cout << '\n';
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}