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
    int findHcf(int first, int second){
        if (first > second){
            swap(first, second);
        }

        while (first){
            if (second % first == 0){
                return first;
            }
            int temp = first;
            first = second % first;
            second = temp;
        }
        return first;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *curr = head;
        while(curr && curr->next){
            int hcf = findHcf (curr->val, curr->next->val);
            ListNode *next = curr->next;
            curr->next = new ListNode(hcf);
            curr->next->next = next;
            curr = curr->next->next;
        }
        return head;
    }
};