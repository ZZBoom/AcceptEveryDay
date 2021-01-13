class Solution {
public:
    int find(int x, const std::vector<int> &f) {
        if (f[x] == x) {
            return x;
        }
        return find(f[x], f);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for (auto &item : edges) {
            n = std::max(n, item[0]);
            n = std::max(n, item[1]);
        }
        std::vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            f[i] = i;
        }
        for (auto &item : edges) {
            int x = find(item[0], f);
            int y = find(item[1], f);
            if (x == y) {
                return item;
            }
            f[x] = y;
        }
        return {};
    }
};
