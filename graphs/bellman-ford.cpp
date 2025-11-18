#include <vector>
#include <limits>

#define INF numeric_limits<long long>::max()

using std::vector, std::pair, std::numeric_limits;

bool bellman_ford(vector<vector<pair<int, int>>>& graph, int s, vector<long long>& distance) {
    int n = graph.size();

    for (int i = 0; i < n; i++) distance[i] = numeric_limits<long long>::max();
    distance[s] = 0;

    for (int k = 0; k < (n - 1); k++) {
        for (int i = 0; i < n; i++) {
            for (auto& e : graph[i]) {
                int j = e.first;
                int weight_i_j = e.second;

                if (distance[i] != INF && distance[j] > distance[i] + weight_i_j) distance[j] = distance[i] + weight_i_j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto& e : graph[i]) {
            int j = e.first;
            int weight_i_j = e.second;

            if (distance[i] != INF && distance[j] > distance[i] + weight_i_j) {
                // negative cycle detected
                return true;
            }; 
        }
    } 

    return false;
}