class Solution {
public:

    int numTrees(int n) {
        // F(i, n): 以 i 为根的树的个数
        // F(i, n) = G(i - 1) * G(n - i)
        // G[n] = sigma{F(i, n)};
        // G[n] = sigma{G(i - 1) * G(n - i)};
        std::vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};
