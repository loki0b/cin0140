#include <bits/stdc++.h>
using namespace std;

#define LL_MAX numeric_limits<long long>::max()

void floyd_warshall(vector<vector<long long>>& graph) {
    int n = graph.size();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] != LL_MAX && graph[k][j] != LL_MAX && graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int solve() {
    int N, E, T, M;

    cin >> N >> E >> T >> M;
    
    vector<vector<long long>> graph(N, vector<long long>(N, LL_MAX));
    for (int i = 0; i < M; i++) {
        int a, b, c;

        cin >> a >> b >> c;
        graph[a - 1][b - 1] = (long long)c;
    }

    for (int i = 0; i < N; i++) graph[i][i] = 0;
    floyd_warshall(graph);

    int count = 0;
    for (int i = 0; i < N; i++) if (graph[i][E - 1] <= T) count++;

    return count;
}

int main() {
    int tc;

    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cout << solve();
        if (i < tc - 1) cout << "\n\n";
    }
    cout << '\n';
    
    return 0;
}