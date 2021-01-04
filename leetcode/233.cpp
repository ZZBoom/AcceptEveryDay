class Solution {
public:
    long long dfs(bool limit, const std::vector<long long> a, int pos, std::vector<long long> &dp, long long cnt, std::vector<long long> &pw) {
        if (pos == -1) {
            return cnt;
        }
        if (false == limit && dp[pos] != -1) {
            return dp[pos] + cnt * pw[pos];
        }
        long long temp = 0;
        int p = limit ? a[pos] : 9;
        for (int i = 0; i <= p; i++) {
            temp += dfs(limit && i == p, a, pos - 1, dp, cnt + (i == 1), pw);
        }
        if (false == limit) {
            dp[pos] = temp;
        }
        return temp;
    }

    int countDigitOne(int n) {
        std::vector<long long> a;
        while(n > 0) {
            a.push_back(n % 10);
            n /= 10;
        }
        int sz = a.size();
        std::vector<long long> pw(sz, 1);
        long long temp = 1;
        for (int i = 0; i < sz; i++) {
            pw[i] = temp * 10;
            temp = pw[i];
        }
        std::vector<long long> dp(a.size(), -1);
        return dfs(true, a, sz - 1, dp, 0, pw);
    }
};


