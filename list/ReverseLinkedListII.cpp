/**
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 *
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 *
 * return 1->4->3->2->5->NULL.
 *
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || !head->next) return head;

        ListNode dummy(-1);
        dummy.next = head;
        ListNode *previous = &dummy, *current = head, *tail;
        for (int i = 1; i <= n; ++i) {
            if (i < m) {
                previous = previous->next;
                current = current->next;
            } else if (i == m) {
                tail = previous->next;
                current = current->next;
            } else {
                ListNode *next = current->next;
                current->next = previous->next;
                previous->next = current;
                tail->next = next;
                current = next;
            }
        }

        return dummy.next;
    }
};