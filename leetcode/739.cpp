class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        struct Node {
            int index;
            int val;
        };
        std::stack<Node> sta;
        std::vector<int> ans;
        int n = static_cast<int> (T.size());
        for (int i = n - 1; i >= 0; i--) {
            while(!sta.empty()) {
                auto item = sta.top();
                if (item.val <= T[i]) {
                    sta.pop();
                } else {
                    break;
                }
            }
            if (sta.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(sta.top().index - i);
            }
            sta.push({i, T[i]});
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
