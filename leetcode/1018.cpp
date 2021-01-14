class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        std::vector<bool> ans;
        int tmp = 0;
        for (auto item : A) {
            tmp = ((tmp << 1) % 5 + item) % 5;
            ans.push_back(tmp == 0);
        }
        return ans;
    }
};
