class Solution {
public:
    string removeDuplicateLetters(string s) {
        std::vector<int> nums(26);
        std::vector<bool> vis(26);
        for (auto c : s) {
            nums[c - 'a']++;
        }
        std::string ans;
        for (auto c : s) {
            if (!vis[c - 'a']) {
                while (!ans.empty() && ans.back() > c) {
                    if (nums[ans.back() - 'a'] > 0) {
                        vis[ans.back() - 'a'] = false;
                        ans.pop_back();
                    } else {
                        break;
                    }
                }
                ans.push_back(c);
                nums[c - 'a']--;
                vis[c - 'a'] = true;
            } else {
                nums[c - 'a']--;
            }
        }
        return ans;
    }
};
