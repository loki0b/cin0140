#include <iostream>
#include <vector>
#include <string>

using std::cin, std::cout, std::ios_base, std::vector, std::string;

void dfs(int& k, vector<vector<int>>& g, vector<int>& visited, bool c) {
    visited[k] = 1;

    for (int& v : g[k]){
        if (visited[v] == 1) {
            c = true; 
            
            return;
        }
        if (visited[v] == 0){
            dfs(v, g, visited, c);

            if (c==true) return;
        }
    }

    visited[k] = -1;
}

string solve() {
    int n, k;
    cin >> n;
    cin >> k;
    
    vector<vector< int>> g(n+ 1);
    vector<int> a(n);
    
    for (int i = 0; i < k; i++) {
        
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        for (int j = 0; j < (n - 1); j++) {
            g[a[j]].push_back(a[j+1]);
        }
    }

    vector<int> visited(n+1, 0);
    bool c=false;

    for (int i = 1; i < (n + 1); i++) {
        if (visited[i] == 0){
            dfs(i, g, visited, c);

            if (c == true) return "NO";
        }
    }

    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << solve() << '\n';
    }
}