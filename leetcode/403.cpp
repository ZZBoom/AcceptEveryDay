class Solution {
public:
    std::unordered_map<int, int>mp;
    bool flag;
    int res;
    void dfs(int stone, int pre, std::vector<std::vector<int>>& dp) {
        if (flag || stone == res) {
            flag = true;
            return;
        }
        //printf("%d\n", stone);
        int k_add_0 = stone + pre;
        int k_add_1 = stone + pre + 1;
        int k_del_1 = stone + pre - 1;
        if (k_add_0 > 0) {
            if (mp.find(k_add_0) != mp.end()) {
                int index = mp[k_add_0];
                if (pre > 0 && 0 == dp[index][pre]) {
                    dp[index][pre] = 1;
                    dfs(k_add_0, pre, dp);
                }
            }
        }
        if (k_add_1 > 0) {
            if (mp.find(k_add_1) != mp.end()) {
                int index = mp[k_add_1];
                if (pre + 1 > 0 && 0 == dp[index][pre + 1]) {
                    dp[index][pre + 1] = 1;
                    dfs(k_add_1, pre + 1, dp);
                }
            }
        }
        if (k_del_1 > 0) {
            if (mp.find(k_del_1) != mp.end()) {
                int index = mp[k_del_1];
                if (pre - 1 > 0 && 0 == dp[index][pre - 1]) {
                    dp[index][pre - 1] = 1;
                    dfs(k_del_1, pre - 1, dp);
                }
            }
        }
    }
    bool canCross(vector<int>& stones) {
        for (size_t i = 0; i < stones.size(); i++) {
            int index = i + 1;
            int value = stones[i];
            mp[value] = index;
            res = stones[i];
        }
        int n = stones.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 10, 0));
        dp[1][0] = 1;
        flag = false;
        dfs(0, 0, dp);
        return flag;
    }
};
