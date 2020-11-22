class Solution {
public:
    bool flag;
    std::unordered_map<int, std::string> dict;
    std::unordered_map<std::string, int> mp;
    void dfs(std::string &p, std::string &s, int p_p, int s_p) {
        if (flag) {
            return;
        }
        if (s_p == s.size() && p_p == p.size()) {
            flag = true;
            return;
        }
        if (p_p == p.size() || s_p == s.size()) {
            return;
        }
        int p_v = p[p_p] - 'a';
        if (dict.find(p_v) != dict.end()) {
            auto sz = dict[p_v];
            int i = 0;
            while(s_p < s.size() && i < sz.size()) {
                if (sz[i] != s[s_p]) {
                    return;
                }
                s_p++;
                i++;
            }
            if (i == sz.size()) {
                dfs(p, s, p_p + 1, s_p);
            }
        } else {
            std::string tmp;
            for (int i = s_p; i < s.size(); i++) {
                tmp += s[i];
                if (mp.find(tmp) != mp.end()) {
                    continue;
                }
                mp[tmp] = 1;
                dict[p_v] = tmp;
                dfs(p, s, p_p + 1, i + 1);
                mp.erase(tmp);
                dict.erase(p_v);
            }
        }
    }
    bool wordPatternMatch(string pattern, string s) {
        flag = false;
        dfs(pattern, s, 0, 0);
        return flag;
    }
};
