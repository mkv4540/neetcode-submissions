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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *left_node = nullptr, *right_node = nullptr, *prev_left_node = nullptr, *next_right_node = nullptr; 
        if (left == right){
            return head;
        }
        left_node = head;
        right_node = head;
        int index = 0;
        for (index = 1; index < left; index++){
            prev_left_node = left_node;
            left_node = left_node->next;
            right_node = right_node->next;
        }

        for (index = left; index < right; index++){
            right_node = right_node->next;
        }
    
        ListNode *temp = left_node, *prev = right_node->next;
        next_right_node = prev;
        while (temp && temp != next_right_node){
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        if (prev_left_node == nullptr){
            head = prev;
        }else{
            prev_left_node->next = prev;
        }

        left_node->next = next_right_node;

        return head;

    }
};