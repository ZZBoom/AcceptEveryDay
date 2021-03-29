class Solution {
public:

    void dfs(int left, int right, std::string &s, std::vector<std::string> &ans) {
        if (left == 0 && right == 0) {
            ans.push_back(s);
            return;
        }
        if (left > 0) {
            std::string sL = s + "(";
            dfs(left - 1, right, sL, ans);
        }
        if (right > 0 && left < right) {
            std::string sR = s + ")";
            dfs(left, right - 1, sR, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        std::string s = "";
        std::vector<std::string> ans;
        dfs(n, n, s, ans);
        return ans;
    }
};


