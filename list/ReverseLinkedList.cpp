
/**
 * Reverse a singly linked list.
 */

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    //recursively
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *newhead = reverseList(head->next);
        ListNode *tail = newhead;
        while (tail && tail->next)
            tail = tail->next;

        tail->next = head;
        head->next = NULL;

        return newhead;
    }

    //iteratively
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *current = head, *next = head->next;
        head->next = NULL;

        while (next != NULL) {
            ListNode *tmp = next->next;
            next->next = current;
            current = next;
            next = tmp;
        }

        return current;
    }
};
