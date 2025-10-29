#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using std::cin, std::cout, std::ios_base, std::vector, std::queue, std::sort, std::stack;

struct vertex {
    int v;
    bool visited;
    vector<vertex*> adjacency;
};

bool cmp(vertex* a, vertex* b) {
    if (a->v < b->v) return true;

    return false;
}

void bfs(vector<vertex>& graph, vector<int>& predecessor, int s, int t) {
    for (vertex& v: graph) {
        v.visited = false;
    }

    queue<vertex*> q;
    q.push(&graph[s]);
    predecessor[graph[s].v] = graph.size();
    graph[s].visited = true;

    while (!q.empty()) {
        vertex* v = q.front();
        q.pop();

        if (v->v == graph[t].v) {
            break;
        }

        for (vertex* w: v->adjacency) {
            if (w->visited == false) {
                w->visited = true;
                q.push(w);
                predecessor[w->v] = v->v;
            }
        }
    }

    if (!graph[t].visited) cout << -1 << '\n';
    else {

        stack<int> s;
        for (int i = t; i != graph.size(); i = predecessor[i]) {
            s.push(i);
        }

        while (!s.empty()) {
            cout << s.top() << ' ';
            s.pop();
        }
        cout << '\n';
    }
}

void solve() {
    int v, e, p;

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

    for (vertex& v: graph) {
        sort(v.adjacency.begin(), v.adjacency.end(), cmp);
    }

    cin >> p;
    vector<int> predecessor(v);
    for (int i = 0; i < p; i++) {
        int s, t;

        cin >> s;
        cin >> t;

        bfs(graph, predecessor, s, t);
    }

}

int main() {
    int c;

    cin >> c; // 0 < c <= 10^5
    for (int tc = 0; tc < c; tc++) {
        cout << "Caso " << tc + 1 << '\n';
        solve();
    }
    
    return 0;
}