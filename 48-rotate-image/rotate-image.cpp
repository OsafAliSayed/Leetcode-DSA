class Solution {
public:
    vector<int> reverse(vector<int>& m) {
        int l = 0, r = m.size() - 1;
        while (l < r) {
            int temp = m[l];
            m[l] = m[r];
            m[r] = temp;
            l++;
            r--;
        }
        return m;
    }
    void rotate(vector<vector<int>>& matrix) {
        //taking transpose
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // reverse each column
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i] = reverse(matrix[i]);
        }
    }
};