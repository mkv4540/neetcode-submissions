class Node{
public:
    int key, val, freq;
    Node *next, *prev;
    Node(int k, int v){
        key = k;
        val = v;
        freq = 1;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList{
public:
    Node *head, *tail;
    int size;
    DoublyLinkedList(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void add_front(Node *curr){
        curr->next = head->next;
        curr->prev = head;
        head->next->prev = curr;
        head->next = curr;
        size++;
    }

    void removeNode(Node *curr){
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        size--;
    }
    Node* removeLast(){
        if (size == 0)
            return nullptr;
        Node *last = tail->prev;
        removeNode(tail->prev);;
        return last;
    }

};

class LFUCache {
public:
    int cap, min_freq, size;
    unordered_map<int, Node*>KeyNode;
    unordered_map<int, DoublyLinkedList*>FreqList;

    void update(Node *node){
        int curr_freq = node->freq;
        FreqList[curr_freq]->removeNode(node);
        if (curr_freq == min_freq && FreqList[curr_freq]->size == 0){
            min_freq++;
        }
        curr_freq++;
        if (!FreqList.count(curr_freq)){
            FreqList[curr_freq] = new DoublyLinkedList();
        }
        FreqList[curr_freq]->add_front(node);
        node->freq++;
    }
    LFUCache(int capacity) {
        cap = capacity;
        min_freq = 0;
        size = 0;
    }
    
    int get(int key) {
        if (!KeyNode.count(key))
            return -1;

        update(KeyNode[key]);
        return KeyNode[key]->val;
    }
    
    void put(int key, int value) {
        if (KeyNode.count(key)){
            KeyNode[key]->val = value;
            update(KeyNode[key]);
            return;
        }
        if (size == cap){
            DoublyLinkedList *list = FreqList[min_freq];
            Node *remove_to = list->removeLast();
            KeyNode.erase(remove_to->key);
            delete(remove_to);
            size--;
        }
        KeyNode[key] = new Node(key, value);
        if (!FreqList.count(1)){
            FreqList[1] = new DoublyLinkedList();
        }
        FreqList[1]->add_front(KeyNode[key]);
        min_freq = 1;
        size++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */