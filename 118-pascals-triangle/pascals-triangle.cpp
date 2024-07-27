class Solution {
public:
    int nCr(int n, int r) {
        int val = 1;
        for (int i = 1; i <= r; i++) {
            val = val * (n - i + 1);
            val = val / i;
        }
    
        return val;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalsTriangle;
        for (int row = 0; row < numRows; row++) {
            vector<int> column;
            for (int col = 0; col < row + 1; col++) {
                int val = nCr(row, col);
                column.push_back(val);
            }
            pascalsTriangle.push_back(column);
        }
        return pascalsTriangle;
    }
};