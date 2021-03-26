/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *dfs(TreeNode *root, TreeNode *p, TreeNode *q, int& num) {
        if (root == NULL) {
            return NULL;
        }
        if (root == p || root == q) {
            num++;
            dfs(root->left, p, q, num);
            dfs(root->right, p, q, num);
            return root;
        }
        auto lRet = dfs(root->left, p, q, num);
        auto rRet = dfs(root->right, p, q, num);
        if (lRet && rRet) {
            return root;
        }
        return lRet == NULL ? rRet : lRet;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int num = 0;
        auto ret = dfs(root, p, q, num);
        return num == 2 ? ret : NULL;
    }
};
