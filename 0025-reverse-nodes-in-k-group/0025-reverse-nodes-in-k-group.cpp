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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* prevGrpEnd = dummy;
        while(true){
            ListNode* kth = prevGrpEnd;
            for(int i = 0; i < k; i++){
                kth = kth -> next;
                if(!kth) return dummy -> next;
            }
            ListNode* grpStart = prevGrpEnd -> next;
            ListNode* curr = grpStart;
            ListNode* prev = nullptr;
            
            for(int i = 0; i < k; i++){
                ListNode* nextNode = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = nextNode;
            }

            prevGrpEnd -> next = prev;
            grpStart -> next = curr;
            prevGrpEnd = grpStart;
        }
        return dummy -> next;
    }
};