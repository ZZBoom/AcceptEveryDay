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
    int dfs(TreeNode* root, int pre, int &ans) {
        if (root == NULL) {
            return 0;
        }
        ans = std::max(ans, 1);
        int left = 0, right = 0;
        if (root->left) {
            left = dfs(root->left, root->val, ans);
            ans = std::max(ans, left + 1);
        }
        if (root->right) {
            right = dfs(root->right, root->val, ans);
            ans = std::max(ans, right + 1);
        }
        if (left > 0 && right > 0) {
            if (root->val == (root->left->val - 1) && root->val == (root->right->val + 1)) {
                ans = std::max(ans, left + right + 1);
            }
            if (root->val == (root->left->val + 1) && root->val == (root->right->val - 1)) {
                ans = std::max(ans, left + right + 1);
            }
        }

        int ret = 0;
        if (pre == (root->val + 1)) {
            ret = 1;
            if (left > 0 && root->val == (root->left->val + 1)) {
                ret = std::max(ret, left + 1);
            }
            if (right > 0 && root->val == (root->right->val + 1)) {
                ret = std::max(ret, right + 1);
            }
        }

        if (pre == (root->val - 1)) {
            ret = 1;
            if (left > 0 && root->val == (root->left->val - 1)) {
                ret = std::max(ret, left + 1);
            }
            if (right > 0 && root->val == (root->right->val - 1)) {
                ret = std::max(ret, right + 1);
            }
        }

        return ret;
    }

    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        dfs(root, INT_MAX - 1, ans);
        return ans;
    }
};
