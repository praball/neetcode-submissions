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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1, *curr2 = list2;
        ListNode res(0);
        ListNode* resp = &res;
        while(curr1 != nullptr && curr2!= nullptr) {
            if(curr1->val>=curr2->val) {
                resp->next=curr2;
                curr2=curr2->next;
            } else {
                resp->next = curr1;
                curr1 = curr1->next;
            }
            resp = resp->next;
        }
        if(curr1 == nullptr) {
            resp -> next = curr2;
        } else {
            resp -> next = curr1;
        }
        return res.next;
    }
};
