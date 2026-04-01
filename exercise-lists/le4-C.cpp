#include <bits/stdc++.h>
using namespace std;

void collectEntrances(const vector<string> &grid, int H, int W, vector<pair<int,int>> &starts) {
    for (int r = 0; r < H; r++)
        for (int c = 0; c < W; c++)
            if (grid[r][c] == '@')
                starts.push_back({r, c});
}

bool explore(int r, int c,
             int usedSpikes,
             int foundTreasure,
             const vector<string> &grid,
             bool seen[41][41][21][2],
             int H, int W, int maxSpikes)
{
    if (usedSpikes > maxSpikes) return false;
    if (seen[r][c][usedSpikes][foundTreasure]) return false;

    seen[r][c][usedSpikes][foundTreasure] = true;

    int treasureState = foundTreasure;
    if (grid[r][c] == 'x')
        treasureState = 1;

    if (treasureState == 1 && grid[r][c] == '@')
        return true;

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
        if (grid[nr][nc] == '#') continue;

        int spikesNext = usedSpikes + (grid[nr][nc] == 's');

        if (explore(nr, nc, spikesNext, treasureState,
                    grid, seen, H, W, maxSpikes))
            return true;
    }

    return false;
}

string solve() {
    int H, W, maxSpikes;
    cin >> H >> W >> maxSpikes;

    vector<string> maze(H);
    for (int i = 0; i < H; i++)
        cin >> maze[i];

    vector<pair<int,int>> entrances;
    collectEntrances(maze, H, W, entrances);

    for (auto &pos : entrances) {
        bool visited[41][41][21][2] = {};

        int sr = pos.first;
        int sc = pos.second;

        if (explore(sr, sc, 0, 0,
                    maze, visited, H, W, maxSpikes))
            return "SUCCESS";
    }

    return "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve();
    return 0;
}