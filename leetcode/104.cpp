//    1
//   / \
//  2   5
// / \   \
//3   4   6
//
//1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6
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
    void dfs(TreeNode* root) {
        if (root) {
            sta_.push(root);
            dfs(root->left);
            dfs(root->right);
        }
    }
    void flatten(TreeNode* root) {
        while(!sta_.empty()) {
            sta_.pop();
        }
        dfs(root);
        TreeNode *pre = nullptr;
        while(!sta_.empty()) {
            auto now = sta_.front();
            sta_.pop();
            now->left = nullptr;
            now->right = nullptr;
            if (pre) {
                pre->right = now;
            }
            pre = now;
        }
    }
private:
    std::queue<TreeNode*> sta_;
};
