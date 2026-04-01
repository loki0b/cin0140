#include <bits/stdc++.h>
using namespace std;

long long backtrack(
    int i,
    long long sum,
    long long K,
    const vector<long long> &A,
    const vector<vector<int>> &conflict,
    vector<int> &used
) {
    if (sum > K) return 0;

    if (i == (int)A.size())
        return 1;

    long long total = 0;

    total += backtrack(i + 1, sum, K, A, conflict, used);

    for (int x : conflict[i])
        if (used[x])
            return total;

    used[i] = 1;
    total += backtrack(i + 1, sum + A[i], K, A, conflict, used);
    used[i] = 0;

    return total;
}

long long solve() {
    int N, M;
    long long K;

    cin >> N >> M >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<vector<int>> conflict(N);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        conflict[x].push_back(y);
        conflict[y].push_back(x);
    }

    vector<int> used(N, 0);

    long long result = backtrack(0, 0, K, A, conflict, used);

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve();

    return 0;
}
