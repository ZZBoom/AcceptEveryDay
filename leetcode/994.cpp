class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        struct Node{
            int step;
            int x;
            int y;
        };
        std::queue<Node> que;
        std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0;j < m; j++) {
                if (grid[i][j] == 2) {
                    Node tmp = {.step = 0, .x = i, .y = j};
                    que.push(tmp);
                }
            }
        }
        int ans = 0;
        int dx[4] = {0, 1, -1, 0};
        int dy[4] = {1, 0, 0, -1};
        while(false == que.empty()) {
            auto now = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int x = now.x + dx[i];
                int y = now.y + dy[i];
                if (x < 0 || y < 0 || x >= n || y >= m) continue;
                if (grid[x][y] == 0) continue;
                if (grid[x][y] == 2) continue;
                if (vis[x][y] == 0) {
                    Node tmp = {.step = now.step + 1, .x = x, .y = y};
                    vis[x][y] = 1;
                    ans = std::max(ans, tmp.step);
                    que.push(tmp);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0;j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
