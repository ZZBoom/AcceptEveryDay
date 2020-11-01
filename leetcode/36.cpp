#include <vector>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    auto n = board.size();
    auto m = board[0].size();
    {
      for (auto i = 0; i < n; i++) {
        std::vector<bool> flag(9, false);
        for (auto j = 0; j < n; j++) {
          if (board[i][j] == '.') {
            continue;
          }
          int c = board[i][j] - '0';
          if (flag[c]) {
            return false;
          } else {
            flag[c] = true;
          }
        }
      }
    }
    {
      for (auto j = 0; j < n; j++) {
        std::vector<bool> flag(9, false);
        for (auto i = 0; i < n; i++) {
          if (board[i][j] == '.') {
            continue;
          }
          int c = board[i][j] - '0';
          if (flag[c]) {
            return false;
          } else {
            flag[c] = true;
          }
        }
      }
    }
    {
      for (auto i = 0; i < n; i += 3) {
        for (auto j = 0; j < n; j += 3) {
          std::vector<bool> flag(9, false);
          for (auto ii = i; ii < i + 3; ii++) {
            for (auto jj = j; jj < j + 3; jj++) {
              if (board[ii][jj] == '.') {
                continue;
              }
              int c = board[ii][jj] - '0';
              if (flag[c]) {
                return false;
              } else {
                flag[c] = true;
              }
            }
          }
        }
      }
    }
    return true;
  }
};
int main() {

}
