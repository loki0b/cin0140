#include <iostream>
#include <vector>

using std::cin, std::cout, std::ios_base, std::vector;

struct vertex {
    int v;
    bool visited;
    vector<vertex*> adjacency;
};

void dfs(vertex* v) {
    v->visited = true;

    for (vertex* w: v->adjacency) {
        if (w->visited == false) {
            dfs(w);
        }
    }
}

void graph_traverse(vector<vertex>& graph) {
    for (vertex& v: graph) {
        v.visited = false;
    }

    int count = 0;
    for (vertex& v: graph) {
        if (v.visited == false) {
            count++;
            dfs(&v);
        }
    }

    cout << count << '\n';
}

void solve() {
    int v, e;

    cin >> v; // 0 < v <= 10^5
    cin >> e; // 0 <= e <= 10^5

    vector<vertex> graph(v);
    
    for (int k = 0; k < e; k++) {
        int i, j;

        cin >> i;
        cin >> j;
        
        graph[i].v = i;
        graph[i].adjacency.push_back(&(graph[j]));

        graph[j].v = j;
        graph[j].adjacency.push_back(&(graph[i]));
    }

    graph_traverse(graph);
}

int main() {
    int c;

    cin >> c; // 0 < c <= 10^5
    for (int tc = 0; tc < c; tc++) {
        solve();
    }
    
    return 0;
}