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
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        ListNode* newNode = new ListNode(value);
        temp->next = newNode;
        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newList = new ListNode();
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                newList = insertNode(newList, list1->val);
                list1 = list1->next;
            } else {
                newList = insertNode(newList, list2->val);
                list2 = list2->next;
            }
        }

        while (list1 != nullptr) {
            newList = insertNode(newList, list1->val);
            list1 = list1->next;
        }

        while (list2 != nullptr) {
            newList = insertNode(newList, list2->val);
            list2 = list2->next;
        }

        return newList->next;
    }
};