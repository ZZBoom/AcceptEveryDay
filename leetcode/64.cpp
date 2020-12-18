class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        assert(n > 0);
        int m = grid[0].size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
        for (int i = 0; i < n ;i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = grid[i][j];
                int res = INT_MAX;
                if (i - 1 >= 0) {
                    res = std::min(res, grid[i][j] + dp[i - 1][j]);
                }
                if (j - 1 >= 0) {
                    res = std::min(res, grid[i][j] + dp[i][j - 1]);
                }
                if (res != INT_MAX) {
                    dp[i][j] = res;
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
