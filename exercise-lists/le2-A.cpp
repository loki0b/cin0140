#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>

using std::cin, std::cout, std::ios_base, std::string, std::set, std::unordered_map, std::queue, std::vector, std::pair, std::sort, std::to_string;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        unordered_map<string, set<string>> adj;
        set<string> names;

        for (int i = 0; i < N; ++i) {
            string a, b, c;
            cin >> a >> b >> c;
            names.insert(a);
            names.insert(b);
            names.insert(c);
            adj[a].insert(b);
            adj[a].insert(c);
            adj[b].insert(a);
            adj[b].insert(c);
            adj[c].insert(a);
            adj[c].insert(b);
        }

        unordered_map<string, int> rank;
        queue<string> q;

        if (names.count("Ahmad")) {
            rank["Ahmad"] = 0;
            q.push("Ahmad");
        }

        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (auto &nxt : adj[cur]) {
                if (!rank.count(nxt)) {
                    rank[nxt] = rank[cur] + 1;
                    q.push(nxt);
                }
            }
        }

        vector<pair<string, string>> out;
        for (auto &name : names) {
            if (rank.count(name))
                out.push_back({name, to_string(rank[name])});
            else
                out.push_back({name, "undefined"});
        }

        sort(out.begin(), out.end(), [&](auto &x, auto &y) {
            auto rx = (x.second == "undefined") ? INT_MAX : stoi(x.second);
            auto ry = (y.second == "undefined") ? INT_MAX : stoi(y.second);
            if (rx != ry) return rx < ry;
            return x.first < y.first;
        });

        cout << out.size() << "\n";
        for (auto &p : out)
            cout << p.first << " " << p.second << "\n";
    }
}
