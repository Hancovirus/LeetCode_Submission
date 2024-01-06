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
        int aLen = 0;
        int bLen = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while(tempA->next) {
            aLen++;
            tempA = tempA->next;
        }
        while(tempB->next) {
            bLen++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        int dif = aLen - bLen;
        if (dif < 0) {
            for (int i = 0; i < abs(dif); i++) {
                tempB = tempB->next;
            }
        } else {
            for (int i = 0; i < dif; i++) {
                tempA = tempA->next;
            }
        }
        while(tempA && tempB) {
            if(tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;
    }
};