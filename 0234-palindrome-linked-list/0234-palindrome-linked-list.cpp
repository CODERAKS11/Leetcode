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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* temp = slow;
        ListNode* newHead = nullptr;
        while(temp != nullptr ){
            ListNode* nextHead = temp -> next;
            temp -> next = newHead;
            newHead = temp;
            temp = nextHead;
        }
        temp = head;
        while(newHead != nullptr){
            if(temp -> val != newHead -> val) return false;
            temp = temp -> next;
            newHead = newHead -> next;
        }
        return true;
    }
};