class Solution {
public:
    void dfs(int num, int n, std::vector<int> &ans) {
        if (num > n) return;
        ans.push_back(num);
        for (int i = 0; i <= 9; ++i){
            if (num * 10 + i > n) return;
            dfs(num * 10 + i, n, ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        std::vector<int> ans;
        ans.reserve(n);
        for (int i = 1; i <= 9; ++i) {
            if (i > n) break;
            dfs(i, n, ans);
        }
        return ans;
    }
};
