#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  int islandPerimeter(vector<vector<int>> &grid) {
    if (grid.empty()) {
      return 0;
    }
    auto coincided_count = [&grid](int i, int j) {
      int n = grid.size();
      int m = grid[0].size();
      int sum = 0;
      if (i > 0) {
        sum += (grid[i - 1][j] == 1);
      }
      if (i < n - 1) {
        sum += (grid[i + 1][j] == 1);
      }
      if (j > 0) {
        sum += (grid[i][j - 1] == 1);
      }
      if (j < m - 1) {
        sum += (grid[i][j + 1] == 1);
      }
      return sum;
    };
    int sum = 0;
    for (auto i = 0; i < grid.size(); i++) {
      for (auto j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 1) {
          sum += 4;
          sum -= coincided_count(i, j);
        }
      }
    }
    return sum;
  }
};

int main() {}
