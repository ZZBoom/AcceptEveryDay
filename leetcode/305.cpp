class Solution {
public:
    std::vector<int> f;

    int getFather(int x) {
        return f[x] == x ? x : getFather(f[x]);
    }
    void merge(int a, int b) {
        f[getFather(a)] = getFather(b);
    }

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        std::vector<int> ans;
        ans.reserve(positions.size());
        std::vector<std::vector<int>> vis(m, std::vector<int>(n, 0));
        int sz = m * n;
        f.resize(sz, 0);
        for (int i = 0; i < sz; i++) {
            f[i] = i;
        }
        int num = 0;
        int dx[4] = {0, 1, -1, 0};
        int dy[4] = {1, 0, 0, -1};
        for (auto item : positions) {
            if (vis[item[0]][item[1]]) {
                ans.push_back(num);
                continue;
            }
            vis[item[0]][item[1]] = 1;

            std::vector<int> temp;
            for (int i = 0; i < 4; i++) {
                int x = dx[i] + item[0];
                int y = dy[i] + item[1];
                if (x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }
                int v = x * n + y;
                if (vis[x][y]) {
                    temp.push_back(v);
                }
            }
            for (int i = 0; i < temp.size(); i++) {
                for (int j = i + 1; j < temp.size(); j++) {
                    int fi = getFather(temp[i]);
                    int fj = getFather(temp[j]);
                    if (fi != fj) {
                        num--;
                        merge(fi, fj);
                    }
                }
            }
            if (temp.size() > 0) {
                int fi = getFather(temp[0]);
                int vv = item[0] * n + item[1];
                int fj = getFather(vv);
                merge(temp[0], vv);
            } else {
                num++;
            }
            ans.push_back(num);
        }
        return ans;
    }
};
