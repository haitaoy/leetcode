/**
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next || k == 0) return head;

        int length = 1;
        ListNode *tail = head;
        while (tail->next) {
            length++;
            tail = tail->next;
        }

        k = length - k % length;
        tail->next = head;
        for (int i = 0; i < k; ++i) {
            tail = tail->next;
        }

        head = tail->next;
        tail->next = NULL;

        return head;
    }

};