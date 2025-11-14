#include <iostream>
#include <vector>
#include <queue>

using std::cout, std::vector, std::queue;

void bfs(vector<vector<int>>& graph, int s, vector<bool>& visited) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int i = 0; i < graph[v].size(); i++) {
            int w = graph[v][i];
            
            if (visited[w] == false) {
                visited[w] = true;
                q.push(w);
            }
        }
        cout << v << '\n';
    }
}

void graph_traverse(vector<vector<int>>& graph, vector<bool>& visited) {
    for (int i = 0; i < graph.size(); i++) visited[i] = false;
    for (int i = 0; i < graph.size(); i++) {
        if (visited[i] == false) bfs(graph, i, visited);
    }
}