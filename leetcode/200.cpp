class Solution {
public:
  int n, m;
  void dfs(int x, int y, std::vector<std::vector<char>> &grid) {
    if (x >= n || y >= m || x < 0 || y < 0) {
      return;
    }
    if (grid[x][y] == '0' || vis[x][y]) {
      return;
    }
    vis[x][y] = 1;
    dfs(x - 1, y, grid);
    dfs(x + 1, y, grid);
    dfs(x, y - 1, grid);
    dfs(x, y + 1, grid);
  }
  std::vector<std::vector<int>> vis;
  int numIslands(vector<vector<char>> &grid) {
    n = grid.size();
    assert(n > 0);
    m = grid[0].size();
    vis.resize(n, std::vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (vis[i][j] || grid[i][j] == '0')
          continue;
        dfs(i, j, grid);
        ans++;
      }
    }
    return ans;
  }
};
