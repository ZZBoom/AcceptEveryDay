class Solution {
public:
    void dfs(int count, std::vector<int> &nums, int start, std::vector<std::vector<int>> &ans, std::vector<int> &temp) {
        if (temp.size() == count) {
            ans.push_back(temp);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (nums.size() - i + temp.size() < count) {
                return;
            }
            temp.push_back(nums[i]);
            dfs(count, nums, i + 1, ans, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        for(int i = 0; i <= nums.size(); i++) {
            std::vector<int> temp;
            dfs(i, nums, 0, ans, temp);
        }
        return ans;
    }
};
