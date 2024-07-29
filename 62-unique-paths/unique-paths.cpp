class Solution {
public:
    int uniquePaths(int m, int n) {
        int total = m + n - 2, r = n - 1;
        long res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (total - r + i) / i;
        }
        return (int)res;
    }
};