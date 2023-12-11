class MyHashMap {
private:
    class Node {
    public:
        int key, value;
        Node* next;
        Node (int k, int v, Node* nxt) {
            key = k;
            value = v;
            next = nxt;
        }
    };
public:
    const static int CAPACITY = 128;
    const static int BASE = 997;
    const static int OFFSET = 1937;
    Node* _lists[CAPACITY] = {};
    MyHashMap() {
        
    }
    
    void put(int key, int value) { /// (4, 40)
        remove(key);
        int slotID = calculateHash(key);
        auto node = new Node(key, value, _lists[slotID]);
        /// node = (1, 10) -> (2, 20) -> (3, 30)
        _lists[slotID] = node;
    }
    
    int get(int key) {
        int slotID = calculateHash(key);
        auto node = _lists[slotID];
        while(node) {
            if (node -> key == key) {
                return node -> value;
            }
            node = node -> next;
        }
        return -1;
    }
    
    void remove(int key) {
        int slotID = calculateHash(key);
        auto node = _lists[slotID];
        
        // If the key doesn't exist, it's a no-op.
        if (node == nullptr) {
            return;
        }
        
        // Key is present at head.
        if (node -> key == key) {
            _lists[slotID] = node -> next;
            delete node;
            return;
        }
        
        while(node && node -> next) {
            if (node -> next -> key == key) {
                auto temp = node -> next;
                node -> next = temp -> next;
                delete temp;
            }
            node = node -> next;
        }
    }
private:
    int calculateHash(int key) {
        return ((key * BASE) + OFFSET) % CAPACITY;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */