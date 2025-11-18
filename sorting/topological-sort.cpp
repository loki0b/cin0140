#include <vector>
#include <stack>
#include <algorithm>

using std::vector, std::stack, std::sort, std::greater;

void topological_sort(vector<vector<int>>& graph, int v, stack<int>& stack, vector<bool>& visited) {
    visited[v] = true;
    sort(graph[v].begin(), graph[v].end(), greater());

    for (int i = 0; i < graph[v].size(); i++) {
        int w = graph[v][i];
        
        if (visited[w] == false) topological_sort(graph, w, stack, visited);
    }
    stack.push(v);
}