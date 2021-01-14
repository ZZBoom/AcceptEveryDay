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
    void dfs(TreeNode *root, std::vector<int> &ans) {
        if (nullptr == root) {
            return;
        } 
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};
