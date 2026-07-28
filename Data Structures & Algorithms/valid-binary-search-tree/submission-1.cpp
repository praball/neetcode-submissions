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

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        rec(root, INT_MAX, INT_MIN);
        return res;
    }

    void rec(TreeNode* root, int max, int min) {
        if (!root) return;
        int rv = root->val;
        if (rv > min && rv < max) {
        } else {
            res = false;
            return;
        }
        if (root->left) {
            rec(root->left, rv, min);
        }
        if (root->right) {
            rec(root->right, max, rv);
        }
    }
};
