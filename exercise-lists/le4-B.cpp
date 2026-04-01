#include <bits/stdc++.h>
using namespace std;

#define BOARD_SIZE 9

bool check(const vector<vector<int>>& board, int row, int col, int value) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[row][i] == value) return false;
        if (board[i][col] == value) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) return false;
    }

    return true;
}

bool solve_sudoku(vector<vector<int>>& board, int i = 0, int j = 0) {
    if (i == 9) return true;
    if (j == 9) return solve_sudoku(board, i + 1, 0);

    if (board[i][j] != 0) return solve_sudoku(board, i, j + 1);

    for (int k = 1; k <= 9; k++) {
        if (check(board, i, j, k)) {
            board[i][j] = k;
            if (solve_sudoku(board, i, j + 1)) return true;
            board[i][j] = 0;
        }
    }

    return false;
}

void solve() {
    vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cin >> board[i][j];
        }
    }

    bool has_solution = solve_sudoku(board);

    if (has_solution) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++)
                cout << board[i][j] << ' ';
            cout << '\n';
        }
    }
    
    else {
        cout << "No solution\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        solve();
    }
    

    return 0;
}