class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return {};
        }
        int m = matrix[0].size();
        std::vector<int> ans;
        ans.reserve(n * m);
        std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
        int x = 0, y = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int f = 0;
        while(true) {
            //printf("%d %d\n", x, y);
            assert(vis[x][y] == 0);
            vis[x][y] = 1;
            ans.push_back(matrix[x][y]);
            int T = 4;
            while(T--) {
                int xx = x + dx[f];
                int yy = y + dy[f];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && vis[xx][yy] == 0) {
                    x = xx;
                    y = yy;
                    break;
                } else {
                    f = (f + 1) % 4;
                }
            }
            if ( T == -1) {
                return ans;
            }
        }
        return ans;
    }
};
