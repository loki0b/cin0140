#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <queue>

#define UNVISITED -1

using   std::cin, std::cout, std::ios_base, std::vector, std::pair, std::string, std::priority_queue,
        std::numeric_limits, std::tuple, std::get, std::to_string;

void dijkstra(vector<vector<pair<int, int>>>& graph, int s, vector<long long>& distance, vector<int>& parent) {
    for (int i = 0; i < graph.size(); i++) {
        distance[i] = numeric_limits<long long>::max();
        parent[i] = UNVISITED;
    }

    priority_queue<tuple<long long, int, int>> pq;
    pq.push({0, s, s});
    distance[s] = 0;

    for (int i = 0; i < graph.size(); i++) {
        int p, v;

        do {
            if (pq.empty()) return;

            p = get<1>(pq.top());
            v = get<2>(pq.top());
            pq.pop();
        } while(parent[v] != UNVISITED);

        parent[v] = p;

        for (auto& e : graph[v]) {
            int w = e.first;
            int weight_v_w = e.second;

            if (parent[w] == UNVISITED && distance[w] > (distance[v] + weight_v_w)) {
                distance[w] = distance[v] + weight_v_w;
                pq.push({-distance[w], v, w});
            } 
        }
    }
}

string solve() {
    int n, m, S, T;

    cin >> n >> m >> S >> T;
    vector<vector<pair<int, int>>> graph(n);
    vector<long long> distance(n);
    vector<int> parent(n);
    for (int i = 0; i < m; i++) {
        int x, y, z;

        cin >> x >> y >> z;
        graph[x].push_back({y, z});
        graph[y].push_back({x, z});
    }

    dijkstra(graph, S, distance, parent);

    if (distance[T] != numeric_limits<long long>::max()) return to_string(distance[T]);
    else return "unreachable";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; 
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cout << "Case #" << i + 1 << ": " << solve() << '\n';
    }

    return 0;
}