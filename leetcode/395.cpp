class Solution {
public:
    int dfs(int l, int r, const int k, const std::string &s) {
        std::vector<int> count(26, 0);
        for (int i = l; i <= r; i++) {
            int index = s[i] - 'a';
            count[index]++;
        }
        char flag = -1;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0 && count[i] < k) {
                flag = i + 'a';
                break;
            }
        }
        if (flag == -1) {
            return r - l + 1;
        }
        int res = 0;
        while (l <= r) {
            while (l <= r && s[l] == flag) {
                l++;
            }
            if (l > r) {
                break;
            }
            int i = l;
            while (i + 1 <= r && s[i + 1] != flag) {
                i++;
            }
            int tmp = dfs(l, i, k, s);
            res = std::max(res, tmp); 
            l = i + 1;
        }
        return res;
    }
    int longestSubstring(string s, int k) {
        int n = static_cast<int> (s.size());
        if (n == 0) {
            return k == 0;
        }
        return dfs(0, n - 1, k, s);
    }
};
