
#include <assert.h>

#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }
    std::unordered_map<int, int> mp;
    for (int i = 0; i < 26; i++) {
      mp[i] = 0;
    }
    int l = 0;
    int r = 0;
    int ans = 1;
    int n = s.size() - 1;
    mp[s[r] - 'a'] = 1;
    while (r < n) {
      while (r + 1 <= n && mp[s[r + 1] - 'a'] == 0) {
        mp[s[r + 1] - 'a'] = 1;
        r++;
      }
      ans = std::max(ans, r - l + 1);
      if (r == n) {
        return ans;
      }
      while (l <= r) {
        mp[s[l] - 'a'] = 0;
        if (s[l] == s[r + 1]) {
          l++;
          break;
        }
        l++;
      }
    }
    return ans;
  }
};

int main() { 
  Solution().lengthOfLongestSubstring("bbbbbbbb"); 
  Solution().lengthOfLongestSubstring("abcabcbb"); 
}
