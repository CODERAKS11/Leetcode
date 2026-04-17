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
    ListNode* reverse(ListNode* head){
        if(!head || head -> next == NULL) return head;
        ListNode* newHead = reverse(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = nullptr;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow = reverse(slow);
        ListNode* temp = head;
        while(slow != nullptr){
            if(slow -> val != temp -> val) return false;
            slow = slow -> next;
            temp = temp -> next;
        }
        
        return true;
    }
};