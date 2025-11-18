#include <iostream>
#include <vector>
#include <queue>
#include <limits>

#define UNVISITED -1

using   std::cin, std::cout, std::ios_base, std::vector, std::pair, std::tuple,
        std::priority_queue, std::numeric_limits, std::get;

int prim(vector<vector<pair<int, int>>>& graph, vector<int>& distance, vector<int>& parent) {
    int cost = 0;

    for (int i = 0; i < graph.size(); i++) {
        distance[i] = numeric_limits<int>::max();
        parent[i] = UNVISITED;
    }

    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 0, 0}); // distance, parent, vertex
    distance[0] = 0;
    for (int i = 0; i < graph.size(); i++) {
        int d, p, v;
        
        do {
            if (pq.empty()) return -1;

            p = get<1>(pq.top());
            v = get<2>(pq.top()); 
            pq.pop();
 
        } while (parent[v] != UNVISITED);

        parent[v] = p;
        cost += distance[v];

        for (auto& e : graph[v]) {
            int w = e.first;

            if (parent[w] == UNVISITED && distance[w] > e.second) {
                distance[w] = e.second;
                pq.push({-distance[w], v, w});
            }
        }
    }

    return cost;
}

void solve() {
    int c, o; // c > 0, o >= 0

    cin >> c >> o;
    vector<vector<pair<int, int>>> graph(c);
    for (int i = 0; i < o; i++) {
        int x, y, z;

        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }

    vector<int> distance(c);
    vector<int> parent(c);

    cout << prim(graph, distance, parent) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    
    return 0;
}