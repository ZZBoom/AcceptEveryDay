class Solution {
/*
@..aA
..B#.
....b
// k + 1
*/
public:
    bool judge(int ex, int ey, int n, int m, vector<string>& grid) {
        if (ex < 0 || ex >= n || ey < 0 || ey >= m) {
            return false;
        }
        if (grid[ex][ey] == '#') {
            return false;
        }
        return true;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        struct Node {
            int key;
            int x;
            int y;
            int step;
        };
        std::queue<Node> que;
        int n = grid.size();
        assert(n > 0);
        int m = grid[0].size();
        int sx, sy;
        int vis[64][31][31] = {0};
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#') continue;
                if (grid[i][j] == '@') {
                    sx = i;
                    sy = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    ans |= (1 << (grid[i][j] - 'a'));
                }
            }
        }
        int dx[4] = {0, -1, 0, 1};
        int dy[4] = {1, 0, -1, 0};
        vis[0][sx][sy] = 1;
        que.push({0, sx, sy, 0});
        while(!que.empty()) {
            auto item = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int ex = dx[i] + item.x;
                int ey = dy[i] + item.y;
                if (false == judge(ex, ey, n, m, grid)) {
                    continue;
                }
                if (vis[item.key][ex][ey]) {
                    continue;
                }
                if (grid[ex][ey] >= 'A' && grid[ex][ey] <= 'Z') {
                    if ((item.key & (1 << (grid[ex][ey] - 'A'))) == 0) {
                        continue;
                    }
                }
                int tmp = item.key;
                if (grid[ex][ey] >= 'a' && grid[ex][ey] <= 'z') {
                    tmp = tmp | (1 << (grid[ex][ey] - 'a'));
                    if (tmp == ans) {
                        return item.step + 1;
                    }
                }
                vis[tmp][ex][ey] = 1;
                que.push({tmp, ex, ey, item.step + 1});
            }
        }
        return -1;
    }
};
