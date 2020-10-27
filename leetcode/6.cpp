#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    struct Pos {
      int x;
      int y;
      char c;
    };
    enum Direction { UP = 0, DOWN };
    std::vector<Pos> poss;
    poss.reserve(s.size());
    int x = 1, y = 1;
    int flag = Direction::DOWN;
    for (auto c : s) {
      // printf("%d %d %c\n", x, y, c);
      poss.push_back({x, y, c});
      if (flag == Direction::DOWN) {
        if (x < numRows) {
          x++;
        } else {
          x--;
          y++;
          flag = Direction::UP;
        }
      } else {
        if (x > 1) {
          x--;
          y++;
        } else {
          x++;
          flag = Direction::DOWN;
        }
      }
    }
    std::sort(poss.begin(), poss.end(), [](Pos &a, Pos &b) {
      if (a.x == b.x) {
        return a.y < b.y;
      }
      return a.x < b.x;
    });
    std::string ans = s;
    for (auto i = 0; i < poss.size(); i++) {
      ans[i] = poss[i].c;
    }
    return ans;
  }
};

int main() {
  std::string temp = "AB";
  int n = 1;
  printf("%s\n", Solution().convert(temp, n).c_str());
}
