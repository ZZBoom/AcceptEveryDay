class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        std::vector<int> left_min(ratings.size());
        std::vector<int> right_min(ratings.size());
        int pre = -1;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if (ratings[i] > pre) {
                left_min[i] = ++ans;
            } else{
                left_min[i] = 1;
                ans = 1;
            }
            pre = ratings[i];
        }
        ans = 0;
        pre = -1;
        for(int i=n-1; i >=0; i--) {
            if (ratings[i] > pre) {
                right_min[i] = ++ans;
            } else {
                right_min[i] = 1;
                ans = 1;
            }
            pre = ratings[i];
        }
        int ret = 0;
        for (int i = 0 ; i < n; ++i) {
            ret += std::max(left_min[i], right_min[i]);
        }
        return ret;
    }
};
