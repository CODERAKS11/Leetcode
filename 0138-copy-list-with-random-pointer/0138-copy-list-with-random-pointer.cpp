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
        unordered_map<Node*, Node*> mpp;
        Node* temp = head;
        Node* dummyNode = new Node(-1);
        Node* curr = dummyNode;
        while(temp){
            Node* node = new Node(temp -> val);
            mpp[temp] = node;
            temp = temp -> next;
        }
        temp = head;
        while(temp){
            Node* copyNode = mpp[temp];
            copyNode -> random = mpp[temp -> random];
            temp = temp -> next;
        }
        temp = head;
        while(temp){
            curr -> next = mpp[temp];
            curr = curr -> next;
            temp = temp -> next;
        }
        return dummyNode -> next;
    }
};