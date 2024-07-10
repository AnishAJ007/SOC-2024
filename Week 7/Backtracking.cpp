#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; ++i)
        if (board[i][col])
            return false;
    
    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; --i, ++j)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    if (row == n)
        return true;

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solveNQueens(board, row + 1, n))
                return true;
            board[row][col] = 0; // backtrack
        }
    }

    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (solveNQueens(board, 0, n)) {
        // Print the board
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }
    return 0;
}
