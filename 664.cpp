class Solution {
public:
    int strangePrinter(string s) {
    // i - j 最小值
    // dp[i][j] = dp[i][k] + dp[k+1][j]
    // if (s[k] == s[j]) dp[i][j] = dp[i][k] + dp[k+1][j] - 1
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        int dp[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int len = 2; i + len - 1 < n; len++) {
                int j = i + len - 1;
                dp[i][j] = len;
                for (int k = i; k < j; k++) {
                    int total = dp[i][k] + dp[k+1][j];
                    if (s[k] == s[j]) total--;
                    dp[i][j] = std::min(dp[i][j], total);
                }
            }
        }
        return dp[0][n-1];
    }
};
