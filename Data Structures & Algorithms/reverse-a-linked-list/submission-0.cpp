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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* temp = head;
        ListNode* res = head;
        vector<int> vec;
        while(temp) {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        for(int i=vec.size()-1;i>=0;i--) {
            res->val = vec[i];
            res = res->next;
        }
        return head;
    }
};
