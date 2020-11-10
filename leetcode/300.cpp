class Solution {
public:
  int find_pos(int v, std::vector<int> &dp, int &len) {
    int left = 0, right = len - 1;
    if (left < right) {
      len++;
      return len - 1;
    }
    while(left <= right) {
      int mid = (left + right) / 2;
      if (dp[mid] >= v) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    if (left == len) {
      ++len;
    }
    return left;
  }
  int lengthOfLIS(vector<int>& nums) {
    std::vector<int> dp(nums.size(), 0);
    int len = 0;
    for (auto i : nums) {
      auto pos = find_pos(i, dp, len);
      dp[pos] = i;
    }
    return len;
  }
};
