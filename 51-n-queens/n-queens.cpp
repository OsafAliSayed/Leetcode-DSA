class Solution {
public:
    bool isValid(vector<string>& board, int row, int col, int n) {
        //diagonals
        int duprow = row;
        int dupcol = col;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;
        while (row >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
        }

        row = duprow;
        col = dupcol;
        while (row >= 0 && col < n) {
            if (board[row][col] == 'Q') return false;
            row--;
            col++;
        }
        return true;
    }
    void solver(vector<vector<string>>& ans, vector<string>& board, int row, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q';
                solver(ans, board, row + 1, n);
                board[row][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0;j < n; j++) {
                row += ".";
            }
            board.push_back(row);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0;j < n; j++) {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }

        solver(ans, board, 0, n);
        return ans;
    }
};