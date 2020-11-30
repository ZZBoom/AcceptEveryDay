class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // dp[i][j] 代表区间 (i, j) 开区间的最大值
        // max(dp[i][k] + dp[k][j] + val[i] * val[k] * val[j]) 枚举 k in 区间 (i, j)
      std::vector<std::vector<int>> dp(nums.size() + 2, std::vector<int>(nums.size() + 2, 0));
      std::vector<int> val(nums.size() + 2);
      val[0] = val[nums.size() + 1] = 1;
      for (int i = 0; i < nums.size(); i++) {
          val[i + 1] = nums[i];
      }
      for (int i = val.size() - 1; i >= 0; i--) {
        for (int len = 3; (i + len - 1) < val.size(); len++) {
          int j = i + len - 1;
          for (int k = i + 1; k < j; k++) {
            dp[i][j] = std::max(dp[i][j], val[i] * val[k] * val[j] + dp[i][k] + dp[k][j]);
          }
        }
      }   
      return dp[0][val.size()-1];
    }
};
