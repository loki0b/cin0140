#include <iostream>
#include <vector>
#include <queue>
#include <limits>
    
using std::cin, std::cout, std::ios_base, std::vector, std::pair, std::priority_queue, std::greater, std::numeric_limits;
    
struct vertex {
    int value;
    bool visited;
    vector<pair<int, int>> adjacency;
};
    
void dijkstra(vector<vertex>& graph, int start, int end) {
    int n = graph.size();
    vector<long long> distance(n, numeric_limits<long long>::max());
    vector<int> parent(n, -1);
    
    distance[start] = 0;
    
    using pii = pair<long long, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
    
        if (graph[u].visited)
            continue;
    
        graph[u].visited = true;
    
        for (auto [v, w] : graph[u].adjacency) {
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
    
    if (distance[end] == numeric_limits<long long>::max()) {
        cout << -1;
        return;
    }
    
    vector<int> path;
    for (int v = end; v != -1; v = parent[v]) path.push_back(v + 1);
    for (int i = path.size() - 1; i >= 0; i--) cout << path[i] << " ";
    cout << '\n';
    
}
    
void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vertex> graph(n);
    for (int i = 0; i < n; i++)
        graph[i].value = i;
    
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        graph[a].adjacency.push_back({b, w});
        graph[b].adjacency.push_back({a, w});
    }
    
    dijkstra(graph, 0, n - 1);
}
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
}