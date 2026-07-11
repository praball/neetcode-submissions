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
    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head->next, *res = head;
        int mid = 1;
        while(fast!= nullptr && fast->next!=nullptr) {
            mid++;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* half = slow->next;
        slow->next = nullptr;
        ListNode *curr = half, *prev = nullptr;
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // while(prev!=nullptr) {
        //     cout<<prev->val<<" ";
        //     prev = prev->next;
        // }
        // while(res!=nullptr) {
        //     cout<<res->val<<" ";
        //     res = res->next;
        // }
        ListNode* res1 = prev;

        while(res!=nullptr && res->next!=nullptr) {
            ListNode* tmp = res1, *temp = res->next;
            // cout<<res1->val<<" ";
            res->next = tmp;
            res1 = res1->next;
            res->next->next = temp;
            // cout<<res1->val<<" ";
            res = temp;
            // cout<<res->val<<" \n";
        }
        if(res1!=nullptr) res->next = res1;
    }
};
