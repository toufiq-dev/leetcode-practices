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
        if (!head) return nullptr;

        // Step 1: Create a map to associate original nodes with their copies.
        unordered_map<Node*, Node*> nodeMap;

        // Step 2: First pass - Create copies of nodes and store them in the map.
        auto current = head;
        while (current) {
            nodeMap[current] = new Node(current -> val);
            current = current -> next;
        }

        // Step 3: Second pass - Adjust next and random pointers.
        current = head;
        while (current) {
            Node* copyNode = nodeMap[current];
            copyNode -> next = nodeMap[current -> next];
            copyNode -> random = nodeMap[current -> random];
            current = current -> next;
        }

        // Step 4: Return the head of the copied list.
        return nodeMap[head];
    }
};

