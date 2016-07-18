/**
 * Sort a linked list using insertion sort.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode dummy(INT_MIN);
        ListNode *previous = &dummy, *current = head, *tail = head, *next = head->next;
        dummy.next = head;

        while (next) {
            ListNode *tmp = next->next;
            for (previous = &dummy, current = dummy.next; current != next;) {
                if (next->val >= current->val) {
                    previous = previous->next;
                    current = current->next;
                } else {
                    tail->next = next->next;
                    next->next = current;
                    previous->next = next;
                    break;
                }
            }
            if (current->val >= tail->val)
                tail = current;
            next = tmp;
        }

        return dummy.next;
    }
};