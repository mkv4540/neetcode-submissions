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
        ListNode* slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *curr = slow->next, *prev = nullptr, *nextNode;
        slow->next = nullptr;  // ← CUT the list here before reversing
        while (curr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        ListNode *temp = head, *mid = prev, *nextSlow;
        while (temp != nullptr && mid != nullptr){
            nextNode = temp->next;
            nextSlow = mid->next;
            temp->next = mid;
            mid->next = nextNode;
            mid = nextSlow;
            temp = nextNode;
        }
    }
};
