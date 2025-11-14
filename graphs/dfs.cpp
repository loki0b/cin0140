#include <iostream>
#include <vector>

using std::cout, std::vector;

void dfs(vector<vector<int>>& graph, int v, vector<bool>& visited){
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); i++) {
        cout << v << '\n';
        
        int w = graph[v][i];
        if (visited[w] == false) dfs(graph, w, visited);
    }
}

void graph_traverse(vector<vector<int>>& graph, vector<bool>& visited) {
    for (int i = 0; i < graph.size(); i++) visited[i] = false;
    for (int i = 0; i < graph.size(); i++) {
        if (visited[i] == false) dfs(graph, i, visited);
    }
}