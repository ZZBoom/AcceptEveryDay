class Solution {
public:
    struct Node {
        int next[2];
    };
    void add(std::vector<Node> &tree, int x, int &total) {
        int t, cur = 0;
        for (int i = 31; i >= 0; i--) {
            t = (x >> i) & 1;
            if (tree[cur].next[t] == -1) {
                tree[cur].next[t] = ++total;
            }
            cur = tree[cur].next[t];
        }
    }
    int find(std::vector<Node> &tree, int x) {
        int ret = 0;
        int cur = 0;
        int t;
        for (int i = 31; i >= 0; i--) {
            t = (x >> i) & 1;
            if (tree[cur].next[!t] != -1) {
                t = !t;
            }
            ret |= (t << i);
            cur = tree[cur].next[t];
        }
        return ret;
    }
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int maxn = n * 31 + 7;
        std::vector<Node> tree(n * 31 + 7, {-1, -1});

        //for (int i = 0; i < maxn; i++) {
        //    tree[i].next[0] = tree[i].next[1] = -1;
        //}
        int total = 0;
        int ans = -1;
        for (auto num : nums) {
            add(tree, num, total);
            ans = std::max(ans, num ^ find(tree, num));
        }
        return ans;
    }
};
