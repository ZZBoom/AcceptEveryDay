class Solution {
public:
    bool flag;
    void dfs(int xx, int yy, std::vector<std::vector<int>> &vis, int count, int n, int m, vector<vector<char>>& board) {
        if (xx == 0 || xx == n - 1 || yy == 0 || yy == m - 1) {
            flag = false;
        }
        int dx[4] = {0, -1, 1, 0};
        int dy[4] = {1, 0, 0, -1};
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + xx;
            int y = dy[i] + yy;
            if (x < 0 || y < 0 || x >= n || y >= m) {
                continue;
            }
            if (vis[x][y] > 0 || board[x][y] == 'X') {
                continue;
            }
            vis[x][y] = count;
            dfs(x, y, vis, count, n, m, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) {
            return;
        }
        int m = board[0].size();
        std::unordered_map<int, int> mp;
        std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
        int count = 1;
        mp[0] = 0;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] > 0 || board[i][j] == 'X') {
                    continue;
                }
                flag = true;
                vis[i][j] = count;
                dfs(i, j, vis, count, n, m, board);
                if (flag) {
                    mp[count] = 1;
                } else {
                    mp[count] = 0;
                }
                count++;
            }
        }
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp[vis[i][j]] == 1) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
