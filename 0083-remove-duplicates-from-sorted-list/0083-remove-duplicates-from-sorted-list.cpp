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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int last = head->val;
        ListNode* temp = head;
        ListNode* tempnext = temp->next;
        while (temp != nullptr) {
            if (temp->next != nullptr && temp->next->val == last) {
                tempnext = temp->next;
                while (tempnext != nullptr && tempnext->val == last) {
                    tempnext = tempnext->next;
                }
                temp->next = tempnext;
            }
            temp = temp->next;
            if (temp != nullptr)
                last = temp->val;
        }
        return head;
    }
};