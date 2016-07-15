/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *    After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head || n < 0) return NULL;

        ListNode dummy(-1);
        dummy.next = head;
        ListNode *previous = &dummy;
        ListNode *current = head, *tail = head;
        while (n-- > 1 && tail) tail = tail->next;
        while (tail && tail->next) {
            current = current->next;
            tail = tail->next;
            previous = previous->next;
        }
        if (current) {
            previous->next = current->next;
            delete current;
        }
        return dummy.next;
    }
};