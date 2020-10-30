#include <assert.h>
#include <cstdio>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string intToRoman(int num) {
    int div[4] = {1000, 100, 10, 1};
    std::string ans = "";

    for (int i = 0; i < 4; i++) {
      int d = num / div[i];
      printf("%d\n", num);
      if (d == 0)
        continue;
      if (d == 4) {
        if (i == 1) {
          ans += "CD";
        } else if (i == 2) {
          ans += "XL";
        } else if (i == 3) {
          ans += "IV";
        } else {
          assert(false);
        }
      } else if (d == 9) {
        if (i == 1) {
          ans += "CM";
        } else if (i == 2) {
          ans += "XC";
        } else if (i == 3) {
          ans += "IX";
        } else {
          assert(false);
        }
      } else if (d == 5) {
        if (i == 1) {
          ans += "D";
        } else if (i == 2) {
          ans += "L";
        } else if (i == 3) {
          ans += "V";
        } else {
          assert(false);
        }
      } else {
        while (d > 0) {
          if (i == 1) {
            if (d >= 5) {
              ans += "D";
              d -= 5;
            } else {
              ans += "C";
              d--;
            }
          } else if (i == 2) {
            if (d >= 5) {
              ans += "L";
              d -= 5;
            } else {
              ans += "X";
              d--;
            }
          } else if (i == 3) {
            if (d >= 5) {
              ans += "V";
              d -= 5;
            } else {
              ans += "I";
              d--;
            }
          } else {
            ans += "M";
            d--;
          }
        }
      }
      num -= num / div[i] * div[i];
    }
    return ans;
  }
};

int main() { printf("%s\n", Solution().intToRoman(58).c_str()); }
