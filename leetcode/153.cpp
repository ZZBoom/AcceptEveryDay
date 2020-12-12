class Solution {
public:
    // 
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (nums.back() >= nums[0]) {
            return nums[0];
        }
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (nums[mid] >= nums[0]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        assert(nums[l] >= nums[0]);
        return nums[l + 1];
    }
};
