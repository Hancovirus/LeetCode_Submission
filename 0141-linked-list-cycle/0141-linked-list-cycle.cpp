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
    bool hasCycle(ListNode *head) {
        ListNode* move = head;
        ListNode* move2 = head;
        while (move && move2) {
            move = move->next;
            move2 = move2->next;
            if (!move2) {
                return false;
            }
            move2 = move2->next;
            if (move == move2)
                return true;
        }
        return false;
    }
};