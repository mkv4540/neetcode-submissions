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
        ListNode *temp = head, *prev = head;
        for (int index = 0; index < n; index++){
            temp = temp->next;
        }
        if (temp == nullptr){
            return head->next;
        }
        while (temp->next){
            temp = temp->next;
            prev = prev->next;
        }
        ListNode * q = prev->next;
        prev->next = prev->next->next;
        q = nullptr;
        return head;
    }
};
