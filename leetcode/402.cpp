class Solution {
public:
    bool judge(char x, char y) {
        int xx = x - '0';
        int yy = y - '0';
        return xx > yy;
    }
    string removeKdigits(string num, int k) {
        std::vector<char> sta;
        int count = 0;
        for (auto c : num) {
            while(!sta.empty() && count < k && judge(sta.back(), c)) {
                sta.pop_back();
                count++;
            }
            sta.push_back(c);
        }
        while(!sta.empty() && count < k) {
            sta.pop_back();
            count++;
        }
        std::string ans = "";
        bool is_first_zero = true;
        for (auto c : sta) {
            if (is_first_zero && c == '0') {
                continue;
            }
            is_first_zero = false;
            ans.push_back(c);
        }
        return ans == "" ? "0" : ans;
    }
};
