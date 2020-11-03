#include <assert.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
  vector<int> f, sz;
  int n, m, count;

  int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

  void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy)
      return;
    if (sz[fx] < sz[fy]) {
      f[fx] = fy;
      sz[fy] += sz[fx];
    } else {
      f[fy] = fx;
      sz[fx] += sz[fy];
    }
  }

  void buildUnionFind(const vector<vector<int>> &matrix) {
    f.resize(count);
    sz.resize(count, 1);
    for (int i = 0; i < m * n; i++) {
      f[i] = i;
    }

    for (int i = 0; i < m; i++) {
      std::unordered_map<int, vector<int>> seen;
      for (int j = 0; j < n; j++) {
        seen[matrix[i][j]].push_back(i * n + j);
      }
      for (const auto &it : seen)
        for (int k = 1; k < it.second.size(); k++)
          merge(it.second[k - 1], it.second[k]);
    }

    for (int j = 0; j < n; j++) {
      std::unordered_map<int, vector<int>> seen;
      for (int i = 0; i < m; i++) {
        seen[matrix[i][j]].push_back(i * n + j);
      }
      for (const auto &it : seen)
        for (int k = 1; k < it.second.size(); k++)
          merge(it.second[k - 1], it.second[k]);
    }
  }

public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix) {
    m = matrix.size();
    n = matrix[0].size();
    count = n * m;
    buildUnionFind(matrix);

    vector<int> order(m * n);
    for (int i = 0; i < m * n; i++)
      order[i] = i;
    sort(order.begin(), order.end(), [&](int x, int y) {
      int fx = find(x), fy = find(y);
      int vx = matrix[fx / n][fx % n], vy = matrix[fy / n][fy % n];
      if (vx != vy)
        return vx < vy;
      return fx < fy;
    });

    vector<int> row(m, 0), col(n, 0);
    vector<vector<int>> ans(m, vector<int>(n));
    int i = 0;
    while (i < m * n) {
      int cur = find(order[i]);
      int j = i;
      int ma = 0;
      while (j < m * n && find(order[j]) == cur) {
        int x = order[j] / n, y = order[j] % n;
        if (ma < row[x])
          ma = row[x];
        if (ma < col[y])
          ma = col[y];
        j++;
      }
      while (i < j) {
        int x = order[i] / n, y = order[i] % n;
        ans[x][y] = ma + 1;
        i++;
        if (row[x] < ma + 1)
          row[x] = ma + 1;
        if (col[y] < ma + 1)
          col[y] = ma + 1;
      }
    }

    return ans;
  }
};

int main() {
  auto print = [](std::vector<std::vector<int>> &ans) {
    for (auto ii : ans) {
      for (auto i : ii) {
        printf("%d ", i);
      }
      printf("\n");
    }
  };
  std::vector<std::vector<int>> v{{-37, -50, -3, 44},
                                  {-37, 46, 13, -32},
                                  {47, -42, -3, -40},
                                  {-17, -22, -39, 24}};
  // {{20, -21, 14}, {-19, 4, 19}, {22, -47, 24}, {-19, 4, 19}}
  //{{7, 3, 6}, {1, 4, 5}, {9, 8, 2}, {9, 8, 2}};
  print(v);
  auto ans = Solution().matrixRankTransform(v);
  print(ans);
}
