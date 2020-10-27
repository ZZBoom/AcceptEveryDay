#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    auto stoi_s = [](const std::string &str) {
      bool flag = str[0] == '-';
      long long ans = 0;
      for (auto c : str) {
        if (c <= '9' && c >= '0') {
          ans = ans * 10 + c - '0';
          if (flag) {
            long long a = -ans;
            if (a < INT_MIN) {
              return INT_MIN;
            }
          } else {
            if (ans > INT_MAX) {
              return INT_MAX;
            }
          }
        }
      }
      if (flag) {
        ans = -ans;
      }
      return static_cast<int>(ans);
    };
    bool blank_flag = true;
    int start_pos = 0;
    int valid_pos = -1;
    for (auto i = 0; i < s.size(); i++) {
      if ((i == 0 || blank_flag) && (s[i] == '-' || s[i] == '+')) {
        blank_flag = false;
      } else if (s[i] <= '9' && s[i] >= '0') {
        valid_pos = i;
        blank_flag = false;
      } else if (s[i] == ' ' && blank_flag) {
        start_pos = i + 1;
      } else {
        break;
      }
    }
    if (valid_pos == -1) {
      return 0;
    }
    printf("%d %d\n", start_pos, valid_pos + 1);
    int ans = stoi_s(s.substr(start_pos, valid_pos - start_pos + 2));
    return ans;
  }
};
int main() {
  std::string temp = "  -0012a42";
  printf("%d\n", Solution().myAtoi(temp));
}
