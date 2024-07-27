class Solution {
public:
    long long nCr(int n, int r) {
        long long val = 1;
        for (int i = 0; i < r; i++) {
            val = val * (n - i);
            val = val / (i + 1);
        }
        return val;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for (int col = 0; col < rowIndex + 1; col++) {
            row.push_back(nCr(rowIndex, col));
        }
        return row;
    }
};