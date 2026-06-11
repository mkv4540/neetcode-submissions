/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr = head;
        map<Node*, Node*>copy_map;
        while (curr){
            copy_map[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr){
            copy_map[curr]->next = copy_map[curr->next];
            copy_map[curr]->random = copy_map[curr->random];
            curr = curr->next;
        }
        return copy_map[head];
    }
};
