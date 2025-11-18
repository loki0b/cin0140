#include <iostream>
#include <vector>
#include <limits>
#include <queue>

#define UNVISITED -1

using   std::cin, std::cout, std::ios_base, std::vector, std::pair,
        std::priority_queue, std::numeric_limits, std::tuple, std::get;

void prim(vector<vector<pair<int, int>>>& graph, vector<long long>& distance, vector<int>& parent) {
    for (int i = 0; i < graph.size(); i++) {
        distance[i] = numeric_limits<long long>::max();
        parent[i] = UNVISITED;
    }

    priority_queue<tuple<long long, int, int>> pq;
    pq.push({0, 0, 0}); // distance, parent, vertex
    distance[0] = 0;
    for (int i = 0; i < graph.size(); i++) {
        int p, v;
        
        do {
            if (pq.empty()) return;

            p = get<1>(pq.top());
            v = get<2>(pq.top());
            pq.pop();
 
        } while (parent[v] != UNVISITED);

        parent[v] = p;

        for (auto& e : graph[v]) {
            int w = e.first;

            if (parent[w] == UNVISITED && distance[w] > e.second) {
                distance[w] = e.second;
                pq.push({-distance[w], v, w});
            }
        }
    }
}