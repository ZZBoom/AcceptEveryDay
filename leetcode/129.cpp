#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

 Definition for a binary tree node.
 struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
 public:
   int sumNumbers(TreeNode *root) {
     if (root == NULL) {
       return 0;
     }
     std::queue<TreeNode *> que;
     que.push(root);
     int sum = 0;
     while (false == que.empty()) {
       auto top = que.front();
       que.pop();
       if (top->left != NULL) {
         top->left->val += top->val * 10;
         que.push(top->left);
       }
       if (top->right != NULL) {
         top->right->val += top->val * 10;
         que.push(top->right);
       } 
       if (top->left == NULL && top->right == NULL) {
         sum += top->val;
       }
     }
     return sum;
   }
 };

 int main() {}
