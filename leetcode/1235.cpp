class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        struct Node{
            int st;
            int ed;
            int pt;
        };
        int n = endTime.size();
        if (n == 0) {
            return 0;
        }
        std::vector<int> dp(n, 0);
        std::vector<Node> its(n);
        for (int i = 0; i < n; i++) {
            its[i].st = startTime[i];
            its[i].ed = endTime[i];
            its[i].pt = profit[i];
        }
        std::sort(its.begin(), its.end(), [](const Node &a, const Node &b) {
            return a.ed < b.ed;
        });
        int ans = its[0].pt;
        for (int i = 0; i < n; i++) {
            if (i >= 1) {
                dp[i] = std::max(dp[i - 1], its[i].pt);
            } else {
                dp[i] = its[i].pt;
            }
            int l = 0, r = i - 1;
            while(l < r) {
                int mid = l + (r - l + 1) / 2;
                if (its[mid].ed <= its[i].st) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (its[l].ed <= its[i].st) {
                dp[i] = std::max(dp[i - 1], dp[l] + its[i].pt);
            }
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};
