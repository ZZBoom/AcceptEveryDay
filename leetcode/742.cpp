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
    void initFa(TreeNode *root, TreeNode *fa, std::vector<TreeNode *> &fas, int k, TreeNode &k_node) {
      if (root == nullptr) {
        return;
      }
      if (root->val == k) {
        k_node = *root;
      }
      fas[root->val - 1] = fa;
      initFa(root->left, root, fas, k, k_node);
      initFa(root->right, root, fas, k, k_node);
    }

    int findClosestLeaf(TreeNode* root, int k) {
      TreeNode k_node;
      std::vector<TreeNode *> fas(1000); 
      std::vector<bool> vis;
      vis.resize(1000);
      initFa(root, nullptr, fas, k, k_node);
      std::queue<TreeNode *> que;
      que.push(&k_node);
      vis[k_node.val - 1] = true;
      while(!que.empty()) {
        auto node = que.front();
        que.pop();
        if (node->right == nullptr && node->left == nullptr) {
          return node->val;
        }
        if (node->right && !vis[node->right->val - 1]) {
            vis[node->right->val - 1] = true;
            que.push(node->right);
        }
        if (node->left && !vis[node->left->val - 1]) {
            vis[node->left->val - 1] = true;
            que.push(node->left);
        }
        if (fas[node->val - 1] && !vis[fas[node->val - 1]->val - 1]) {
            vis[fas[node->val - 1]->val - 1] = true;
            que.push(fas[node->val - 1]);
        }
      }
      return -1;
    }
};

