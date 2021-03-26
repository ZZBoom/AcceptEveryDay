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
    void dfs(TreeNode* root) {
        if (root) {
            dfs(root->left);
            vec_.push_back(root);
            dfs(root->right);
        }
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root);
        if (vec_.back() == p) {
            return NULL;
        }
        int count = 0;
        for (auto item : vec_) {
            if (item == p) {
                return vec_[count+1];
            }
            count++;
        }
        return NULL;
    }
private:
    std::vector<TreeNode *> ec_;
};v
