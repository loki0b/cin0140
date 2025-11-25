#include <vector>
#include <limits>

#define LL_MAX numeric_limits<long long>::max()

using std::vector, std::pair, std::numeric_limits;

void floyd_warshall(vector<vector<pair<int, int>>>& graph, vector<vector<long long>>& distance) {
    int n = graph.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) distance[i][j] = 0;
            else distance[i][j] = LL_MAX;
        }
    }

    for (int v = 0; v < n; v++) {
        for (auto& e : graph[v]) {
            int w = e.first;
            int weight_v_w = e.second;

            distance[v][w] = weight_v_w;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][k] != LL_MAX && distance[k][j] != LL_MAX && distance[i][j] > distance[i][k] + distance[k][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }
}