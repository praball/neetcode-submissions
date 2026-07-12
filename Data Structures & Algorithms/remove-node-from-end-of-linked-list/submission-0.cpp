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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode *curr = head, *temp = head;
        while(curr) {
            sz++;
            curr = curr->next;
        }
        int rm = sz-n+1, count = 1;
        // cout<<rm+1;
        if(sz==1) {
            ListNode* res = nullptr;
            return res;
        }
        if(rm == 1) {
            return head->next;
        }
        while((count+1)!=rm) {
            count++;
            temp = temp->next;
        }
        temp ->next = temp->next->next;
        return head;
    }
};
