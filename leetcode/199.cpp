class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    struct NodeInfo{
      TreeNode *p;
      int level;
    };
    std::vector<int> ans;
    std::queue<NodeInfo> que;
    que.push({root, 0});
    while(false == que.empty()) {
      auto item = que.front();
      que.pop();
      if (item.p == NULL) {
        continue;
      }
      if (ans.size() <= item.level) {
        ans.push_back(item.p->val);
      } else {
        ans[item.level] = item.p->val;
      }
      que.push({item.p->left, item.level + 1});
      que.push({item.p->right, item.level + 1});
    }
    return ans;
  }
};
