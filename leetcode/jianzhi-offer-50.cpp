class Solution {
public:
    char firstUniqChar(string s) {
        std::vector<char> order;
        order.reserve(s.size());
        std::unordered_map<char, int> cnt;
        for (auto c : s) {
            if (cnt.find(c) == cnt.end()) {
                order.push_back(c);
                cnt[c] = 1;
            } else {
                cnt[c] = cnt[c] + 1;
            }
        }
        for (auto c : order) {
            if (cnt[c] == 1) {
                return c;
            }
        }
        return ' ';
    }
};
