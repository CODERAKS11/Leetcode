/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0;
        int countB = 0;
        ListNode* temp = headA;
        while(temp  != nullptr){
            countA++;
            temp = temp -> next;
        }
        temp = headB;
        while(temp  != nullptr){
            countB++;
            temp = temp -> next;
        }
        ListNode* slow = nullptr;
        ListNode* fast = nullptr;
        if(countA < countB){
            slow = headA;
            temp = headB;
            while(countA != countB){
                temp = temp -> next;
                countB--;
            }
            fast = temp;
        } else {
            slow = headB;
            temp = headA;
            while(countA != countB){
                temp = temp -> next;
                countA--;
            }
            fast = temp;
        }
    

        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};