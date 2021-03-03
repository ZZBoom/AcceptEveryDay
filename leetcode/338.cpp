   1
  10
  11
 100
 101
 110
 111
1000
1001
1010
1011
1100
1101
1110
1111
class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> ans(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};
