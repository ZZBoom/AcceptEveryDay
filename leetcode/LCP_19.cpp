class Solution {
public:
  int minimumOperations(string leaves) {
    int n = leaves.size();
    int dp[n][3];
    for (int i = 0; i < n; i++) {
      dp[i][0] = dp[i][1] = dp[i][2] = n + 1;
      if (leaves[i] == 'r') {
        if (i == 0) {
          dp[i][0] = 0;
        } else {
          dp[i][0] = dp[i - 1][0];
        }
        if (i >= 1) {
          dp[i][1] = dp[i - 1][0] + 1;
          if (i >= 2) {
            dp[i][1] = std::min(dp[i][1], dp[i - 1][1] + 1);
          }
        }
        if (i >= 2) {
          dp[i][2] = dp[i - 1][1];
          if (i >= 3) {
            dp[i][2] = std::min(dp[i][2], dp[i - 1][2]);
          }
        }
      } else {
        if (i == 0) {
          dp[i][0] = 1;
        } else {
          dp[i][0] = dp[i - 1][0] + 1;
        }
        if (i >= 1) {
          dp[i][1] = dp[i - 1][0];
          if (i >= 2) {
            dp[i][1] = std::min(dp[i][1], dp[i - 1][1]);
          }
        }
        if (i >= 2) {
          dp[i][2] = dp[i - 1][1] + 1;
          if (i >= 3) {
            dp[i][2] = std::min(dp[i][2], dp[i - 1][2] + 1);
          }
        }
      }
    }
    return dp[n - 1][2];
  }
};
