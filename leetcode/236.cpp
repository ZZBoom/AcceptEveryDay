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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        auto left_v = lowestCommonAncestor(root->left, p, q);
        auto right_v = lowestCommonAncestor(root->right, p, q);
        if (left_v != NULL && right_v != NULL) {
            return root;
        }
        if (left_v != NULL) {
            return left_v;
        }
        if(right_v != NULL) {
            return right_v;
        }
        return NULL;
    }
};
