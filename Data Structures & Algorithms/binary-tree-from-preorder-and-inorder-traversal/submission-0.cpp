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
    unordered_map<int, int> m;
    int preIdx = 0;

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = in.size();
        for (int i = 0; i < n; i++) {
            m[in[i]] = i;
        }
        return rec(pre, 0, n-1);
    }

    TreeNode* rec(vector<int>& pre, int i, int k) {
        if(i>k) return nullptr;
        TreeNode* tmp = new TreeNode(pre[preIdx]);
        int mid = preIdx;
        preIdx++;
        tmp->left = rec(pre, i, m[pre[mid]] - 1);
        tmp->right = rec(pre, m[pre[mid]] + 1, k);
        return tmp;
    }
};
