#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    auto is_valid = [s](size_t pos) -> bool {
      return pos >= 0 && pos < s.size();
    };
    size_t max_len = s.size() > 0 ? 1 : 0;
    size_t start_pos = 0;
    for (auto pos = 0; pos < s.size(); pos++) {
      size_t i = pos, j = pos;
      while (is_valid(i - 1) && is_valid(j + 1) && s[i - 1] == s[j + 1]) {
        i--;
        j++;
      }
      if (j - i + 1 > max_len) {
        start_pos = i;
        max_len = j - i + 1;
      }
      i = pos;
      j = i + 1;
      if (is_valid(i) && is_valid(j) && s[i] == s[j]) {
        while (is_valid(i - 1) && is_valid(j + 1) && s[i - 1] == s[j + 1]) {
          i--;
          j++;
        }
        if (j - i + 1 > max_len) {
          start_pos = i;
          max_len = j - i + 1;
        }
      }
    }
    return s.substr(start_pos, max_len);
  }
};

int main() {
  std::string a = "cvvd";
  printf("%s\n", Solution().longestPalindrome(a).c_str());
}
