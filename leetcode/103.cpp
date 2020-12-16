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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        struct Node {
            TreeNode *ptr;
            int val;
        };
        std::queue<Node> que;
        Node first = {.ptr = root, .val = 1};
        std::vector<std::vector<int>> ans;
        que.push(first);
        while(false == que.empty()) {
            auto now = que.front();
            que.pop();
            if (now.ptr == NULL) {
                continue;
            }
            int sz = now.val;
            if (ans.size() < sz) {
                anspush_back(std::vector<int>());
            }
            ans[sz - 1].push_back(now.ptr->val);
            if (now.ptr->left) {
                que.push({now.ptr->left, now.val + 1});
            }
            if (now.ptr->right) {
                que.push({now.ptr->right, now.val + 1});
            }
        }
        int cnt = 0;
        for (auto &v : ans) {
            if (cnt & 1) {
                std::reverse(v.begin(), v.end());
            }
            cnt++;
        }
        return ans;
    }
};
