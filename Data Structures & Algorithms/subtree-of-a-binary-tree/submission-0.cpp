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
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(!root && !sub) return true;
        if(!root || !sub) return false;
        bool a = equal(root, sub), b = isSubtree(root->left, sub), c = isSubtree(root->right, sub);
        // bool b = false, c = false;
        // if(!root->left) {
        //     ;
        // }
        // if(!root->right) {
        //     ;
        // }
        return (a || b || c);
    }

    bool equal(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        bool a = equal(p->left, q->left);
        bool b = equal(p->right, q->right);
        if(a && b) return true;
        return false;
    }
};
