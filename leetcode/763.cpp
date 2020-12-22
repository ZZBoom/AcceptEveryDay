class Solution {
public:
    vector<int> partitionLabels(string S) {
        struct PosInfo{
            int left;
            int right;
        };
        std::vector<PosInfo> flag(26);
        std::vector<int> vis(26, 0);
        for (int i = 0; i < S.size(); i++) {
            int pos = S[i] - 'a';
            if (vis[pos] == 0) {
                vis[pos] = 1;
                flag[pos].left = flag[pos].right = i;
            } else {
                flag[pos].right = i;
            }
        }
        std::vector<int> ans;
        int start = 0;
        int now_max = -1;
        for (int i = 0; i < S.size(); i++) {
            int pos = S[i] - 'a';
            now_max = std::max(flag[pos].right, now_max);
            if (now_max == i) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
