/**
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You must do this in-place without altering the nodes' values.
 *
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        fast = reverseList(fast);

        while (slow && fast) {
            ListNode *next = fast->next;
            fast->next = slow->next;
            slow->next = fast;
            slow = fast->next;
            fast = next;
        }
    }

private:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *previous = head, *current = head->next;
        while (current) {
            ListNode *next = current->next;
            current->next = previous;

            previous = current;
            current = next;
        }
        head->next = NULL;

        return previous;
    }
};