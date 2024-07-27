class Solution {
public:
    long long nCr(int n, int r) {
        long long val = 1;
        for (int i = 1; i <= r; i++) {
            val = val * (n - i + 1);
            val = val / i;
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