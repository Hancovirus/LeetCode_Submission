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
    ListNode* insertNode(ListNode* head, int value) {
        if (head->val == -1) {
            head->val = value;
            return head;
        }
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        ListNode* newNode = new ListNode(value);
        temp->next = newNode;
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp = 0;
        int val = 0;
        ListNode* outPut = new ListNode(-1);
        while(l1 != nullptr || l2 != nullptr) {
            val = 0;
            if (l1 == nullptr) {
                val += l2->val;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                val += l1->val;
                l1 = l1->next;
            } else {
                val += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            val += temp;
            temp = 0;
            if (val > 9) {
                temp = val / 10;
                val = val % 10; 
            }
            outPut = insertNode(outPut, val);
        }
        if (temp != 0) {
            outPut = insertNode(outPut, temp);
        }
        return outPut;
    }
};
