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
    TreeNode *findLeftMax(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->right) {
            return findLeftMax(root->right);
        }
        return root;
    }
    TreeNode * dfs(TreeNode *root, int key, TreeNode *pre) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == key) {
            if (pre == nullptr) {
                if (root->left == nullptr) {
                    return root->right;
                } else if (root->right == nullptr) {
                    return root->left;
                } else {
                    if (root->right->left) {
                        auto leftMax = findLeftMax(root->left);
                        if (leftMax) {
                            leftMax->right = root->right->left;
                        } else {
                            root->left->right = root->right->left;
                        }
                    }
                    root->right->left = root->left;
                    return root->right;
                }
            } else if (pre->val > root->val) {
                if (root->left == nullptr) {
                    pre->left = root->right;
                } else if (root->right == nullptr) {
                    pre->left = root->left;
                } else {
                    pre->left = root->right;
                    if (root->right->left) {
                        auto leftMax = findLeftMax(root->left);
                        if (leftMax) {
                            leftMax->right = root->right->left;
                        } else {
                            root->left->right = root->right->left;
                        }
                    }
                    root->right->left = root->left;
                }
            } else {
                if (root->left == nullptr) {
                    pre->right = root->right;
                } else if (root->right == nullptr) {
                    pre->right = root->left;
                } else {
                    pre->right = root->right;
                    if (root->right->left) {
                        auto leftMax = findLeftMax(root->left);
                        if (leftMax) {
                            leftMax->right = root->right->left;
                        } else {
                            root->left->right = root->right->left;
                        }
                    }
                    root->right->left = root->left;
                }
            }
        } else if (root->val > key) {
            dfs(root->left, key, root);
        } else {
            dfs(root->right, key, root);
        }
        return nullptr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == key && root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        auto head = dfs(root, key, nullptr);
        if (head) {
            return head;
        }
        return root;
    }
};
