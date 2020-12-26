class Solution {
public:
    struct Res{
        std::string word;
        bool is_valid;
        int end_pos;
    };
    Res get_word(std::string &s, int index) {
        Res res = {.word = "", .is_valid = false, .end_pos = 0};
        while(index < s.size() && s[index] == ' ') {
            index++;
        }
        if (index == s.size()) {
            return res;
        }
        std::string temp = "";
        while(index < s.size() && s[index] != ' ') {
            temp.push_back(s[index]);
            index++;
        }
        res.word = temp;
        res.is_valid = true;
        res.end_pos = index;
        return res;
    }
    string reverseWords(string s) {
        std::vector<std::string> ans;
        int index = 0;
        while(true) {
            auto res = get_word(s, index);
            if (res.is_valid) {
                ans.push_back(res.word);
                index = res.end_pos;
            } else {
                break;
            }
        }
        std::reverse(ans.begin(), ans.end());
        std::string res;
        bool flag = false;
        for (auto item : ans) {
            if (flag) {
                res += " ";
            }
            res += item;
            flag = true;
        }
        return res;
    }
};
