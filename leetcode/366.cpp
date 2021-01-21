/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void add(std::vector<std::vector<int>> &ans, int index, TreeNode *root) {
        if (ans.size() <= index) {
            ans.push_back(std::vector<int>());
        }
        ans[index].push_back(root->val);
    }
    int dfs(TreeNode *root, std::vector<std::vector<int>> &ans) {
        if (root == nullptr) {
            return -1;
        }
        if (root->left == nullptr && root->right == nullptr) {
            int index = 0;
            add(ans, index, root);
            return index;
        }
        int l_v = dfs(root->left, ans);
        int r_v = dfs(root->right, ans);
        int index = std::max(l_v, r_v) + 1;
        add(ans, index, root);
        return index;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        std::vector<std::vector<int>> ans;
        dfs(root, ans);
        return ans;
    }
};
