class Solution {
public:
    int characterReplacement(string s, int k) {
        int sz = s.size();
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int sum = 0;
            int left = 0;
            int right = -1;
            while(right + 1 < sz) {
                while(right + 1 < sz && sum <= k) {
                    int index = s[right + 1] - 'A';
                    if (index == i) {
                        right++;
                    } else if (sum < k) {
                        sum++;
                        right++;
                    } else {
                        break;
                    }
                }
                if (sum <= k) {
                    ans = std::max(ans, right - left + 1);
                }
                while(left <= right) {
                    int index = s[left] - 'A';
                    if (sum == k) {
                        if (index != i) {
                            sum--;
                        }
                        left++;
                    } else {
                        break;
                    }
                }
                if (right == left - 1) {
                    left++;
                }
                if (left > right) {
                    right = left - 1;
                }
            }
        }
        return ans;
    }
};
