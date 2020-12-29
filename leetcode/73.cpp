class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return;
        }
        int m = matrix[0].size();
        bool n_flag = false;
        for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                n_flag = true;
                break;
            }
        }
        bool m_flag = false;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                m_flag = true;
                break;
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < m; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                 for (int i = 1; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (n_flag) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        if (m_flag) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
