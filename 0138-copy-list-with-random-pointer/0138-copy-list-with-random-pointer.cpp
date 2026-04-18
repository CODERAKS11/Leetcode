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
        Node* temp = head;
        while(temp){
            Node* node = new Node(temp -> val);
            Node* nextNode = temp -> next;
            temp -> next = node;
            node -> next = nextNode;
            temp = temp -> next -> next;
        }
        temp = head;
        
        while(temp){
            if(temp -> random){
                temp -> next -> random = temp -> random -> next;
            }
            temp = temp -> next -> next;
        }
        temp = head;
        Node* dummyNode = new Node(-1);
        Node* curr = dummyNode;
        while(temp){
            Node* copy = temp -> next;
            curr -> next = copy;
            curr = curr -> next;
            temp -> next = copy -> next;
            temp = temp -> next;
        }
        return dummyNode -> next;
    }
};