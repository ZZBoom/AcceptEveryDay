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
    int sum;
    struct RV{
        bool is_cam;
        bool is_sol;
    };
    RV dfs(TreeNode *root, int pre) {
        RV left{false, false}, right{false, false};
        bool left_son = false;
        bool right_son = false;
        RV ret{false, false};
        if (root->left) {
            left = dfs(root->left, 1);
            left_son = true;
        }
        if (root->right) {
            right = dfs(root->right, 1);
            right_son = true;
        }
        if (left_son || right_son) {
            // 左有 & 没有被处理
            if (left_son && (!left.is_sol)) {
                sum++;
                ret.is_cam = true;
                ret.is_sol = true;
                return ret;
            }
            // 右有 & 没有被处理
            if (right_son && (!right.is_sol)) {
                sum++;
                ret.is_cam = true;
                ret.is_sol = true;
                return ret;
            }
            if(right.is_cam || left.is_cam) {
                ret.is_sol = true;
                return ret;
            }
            assert(left.is_sol == left_son);
            assert(right.is_sol == right_son);
            if (pre == -1) {
                sum++;
            }
            return ret;
        }
        if (pre == -1) {
            sum++;
        }
        return ret;
    }
    int minCameraCover(TreeNode* root) {
        sum = 0;
        dfs(root, -1);
        return sum;
    }
};
