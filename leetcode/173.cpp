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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(!sta_.empty()) {
            sta_.pop();
        }
        pre_order(root);
    }
    
    int next() {
        assert(!sta_.empty());
        int res = sta_.top()->val;
        auto item = sta_.top()->right;
        sta_.pop();
        pre_order(item);
        return res;
    }
    
    bool hasNext() {
        return !sta_.empty();
    }
private:
    void pre_order(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        sta_.push(root);
        pre_order(root->left);
    }
    std::stack<TreeNode *> sta_;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
