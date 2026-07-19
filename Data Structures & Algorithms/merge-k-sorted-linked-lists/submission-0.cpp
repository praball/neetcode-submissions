/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& vec) {
        int n = vec.size();
        ListNode *res = nullptr;
        if(n==0) return res;
        for(int i=1;i<n;i++) {
            vec[i] = merger(vec[i-1], vec[i]);
        }
        return vec[n-1];
    }

    ListNode* merger(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0);
        ListNode *curr = res;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val > l2->val) {
                curr->next = l2;
                l2 = l2->next;
            } else {
                curr->next = l1;
                l1 = l1->next;
            }
            curr = curr->next;
        }
        if(l1 == nullptr) curr->next = l2;
        else curr->next = l1;
        return res->next;
    }
};
