class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        assert(birth.size() > 0);
        int s1[10002] = {0};
        int s2[10002] = {0};
        for (int i = 0; i <birth.size(); i++) {
            s1[birth[i]] += 1;
            s2[death[i] + 1] += 1;
        }
        int ans = 0;
        int min_s = -1;
        for (int i = 1; i <= 10000; i++) {
            s1[i] += s1[i - 1];
            s2[i] += s2[i - 1];
            if (s1[i] - s2[i] > ans) {
                ans = s1[i] - s2[i];
                min_s = i;
            }
        }
        return min_s;
    }
};
