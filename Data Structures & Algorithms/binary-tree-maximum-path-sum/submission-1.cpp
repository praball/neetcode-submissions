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
    int maxi = INT_MIN;

    int maxPathSum(TreeNode* root) {
        rec(root);
        return maxi;
    }

    int rec(TreeNode* root) {
        if (!root) {
            return 0;
        }
        // maxi = max(maxi, childVal + root->val);
        int l = rec(root->left);
        int r = rec(root->right);
        if(l<0) l = 0;
        if(r<0) r = 0;
        int k = l + r + (root->val);
        maxi = max(maxi, k);
        return max(max(l, r) + root->val, root->val);
    }
};
