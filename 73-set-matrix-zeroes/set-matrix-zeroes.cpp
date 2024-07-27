class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0 = false;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j == 0) {
                        col0 = true;
                    }
                    else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        //setting column zeroes
        for (int i = 1; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                //set whole row zero
                for(int j = 0; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        
        //setting row zeroes
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                //set whole row zero
                for(int j = 0; j < matrix[i].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }


        if (col0 == true) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};