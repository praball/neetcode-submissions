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
    bool res = true;

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        rec(root);
        return res;
    }

    int rec(TreeNode* root) {
        if (!root) return 0;
        int l = rec(root->left);
        int r = rec(root->right);
        int diff = abs(l - r);
        if (diff == 0 || diff == 1) {
        } else
            res = false;
        return 1 + max(l, r);
    }
};
