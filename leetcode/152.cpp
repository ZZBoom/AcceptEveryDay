class Solution {
// dp[i] 以 i 为结尾的最大
int max_3(int x, int y, int z) {
    if (x > y && x > z) {
        return x;
    }
    if (y > z) {
        return y;
    }
    return z;
}
int min_3(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    }
    if (y < z) {
        return y;
    }
    return z;
}
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max_3(mx * nums[i], nums[i], mn * nums[i]);
            minF = min_3(mn * nums[i], nums[i], mx * nums[i]);
            ans = std::max(maxF, ans);
        }
        return ans;
    }
};

