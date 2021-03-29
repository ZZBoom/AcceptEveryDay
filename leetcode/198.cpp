class Solution {
 public:
  // dp[i][0] 偷
  // dp[i][1] 不偷
  // [1, 3, 5, 2] = 6
  int rob(vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    if (n == 0) {
      return 0;
    }
    int dp[n][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = nums[0];
    dp[0][1] = 0;
    for (int i = 1; i < n; i++) {
      int maxSteal = 0;
      for (int j = 0; j < i - 1; ++j) {
        maxSteal = std::max(maxSteal, std::max(dp[j][0], dp[j][1]));
      }
      dp[i][0] = std::max(dp[i-1][1], maxSteal) + nums[i];
      int maxPre = 0;
      for (int j = 0; j < i; ++j) {
        maxPre = std::max(maxPre, std::max(dp[j][0], dp[j][1]));
      }
      dp[i][1] = maxPre;
    }
    return std::max(dp[n-1][0], dp[n-1][1]);
  }
};


