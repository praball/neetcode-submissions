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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* poot, TreeNode* qoot) {
        int r = root->val, q = qoot->val, p = poot->val;
        TreeNode* res = root;
        if((r>=p && r<=q) || (r<=p && r>=q)) return root;
        if(r>p) {
            res = lowestCommonAncestor(root->left, poot, qoot);
        } else {
            res = lowestCommonAncestor(root->right, poot, qoot);
        }
        return res;
    }
};
