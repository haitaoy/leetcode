/**
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes
 * of the first two lists.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode *head = (l1->val < l2->val) ? l1 : l2;
        ListNode *current = head;
        l1->val < l2->val ? l1 = l1->next : l2 = l2->next;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1) current->next = l1;
        if (l2) current->next = l2;

        return head;
    }
};