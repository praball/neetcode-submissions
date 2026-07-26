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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) return res;
        q.push(root);
        while (q.size()>0) {
            vector<int> tmp;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode* curr = q.front();
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
                tmp.push_back(curr->val);
                q.pop();
                // cout<<"";
            }
            res.push_back(tmp);
        }
        return res;
    }
};
