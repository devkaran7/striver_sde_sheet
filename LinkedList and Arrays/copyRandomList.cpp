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
private:
    unordered_map<Node*, Node*> mp;
    Node* getDeepCopy(Node* node) {
        if (node == nullptr) return node;
        if (mp.find(node) == mp.end()) {
            mp[node] = new Node(node->val);
        }
        return mp[node];
    }
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        Node* node = head;
        while(node != nullptr) {
            Node* currentNode = getDeepCopy(node);
            if (node->next != nullptr) {
                Node* nextCurrentNode = getDeepCopy(node->next);
                currentNode->next = nextCurrentNode;
            }
            if (node->random != nullptr) {
                Node* randomCurrentNode = getDeepCopy(node->random);
                currentNode->random = randomCurrentNode;
            }
            node = node->next;
        }
        return getDeepCopy(head);
    }
};
