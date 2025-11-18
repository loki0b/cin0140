#include <vector>
#include <limits>

#define LL_MAX numeric_limits<long long>::max()

using std::vector, std::numeric_limits;
using ll = long long;

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