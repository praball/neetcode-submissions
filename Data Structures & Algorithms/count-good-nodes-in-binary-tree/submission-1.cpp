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
    int res = 0;

    int goodNodes(TreeNode* root) {
        rec(root, root->val);
        return res;
    }

    void rec(TreeNode* root, int maxv) {
        if (!root) {
            return;
        }
        if (root->val >= maxv) {
            res++;
            maxv = root->val;
        }
        rec(root->left, maxv);
        rec(root->right, maxv);
    }
};
