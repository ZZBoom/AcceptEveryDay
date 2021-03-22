class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long ans = -100001;
        long long now = 0;
        for (auto item : nums) {
            if (now > 0) {
                now += item;
            } else {
                now = item;
            }
            ans = std::max(now, ans);
        }
        return ans;
    }
};
