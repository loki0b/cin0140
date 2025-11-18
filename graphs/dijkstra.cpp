#include <vector>
#include <limits>
#include <queue>

#define UNVISITED -1

using std::vector, std::pair, std::numeric_limits, std::priority_queue, std::tuple, std::get;

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