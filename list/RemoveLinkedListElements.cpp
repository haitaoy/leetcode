/**
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) return NULL;

        ListNode dummy(-1);
        dummy.next = head;
        ListNode *previous = &dummy, *current = head;

        while (current) {
            if (current->val == val) {
                previous->next = current->next;
                delete current;
                current = previous->next;
            } else {
                previous = current;
                current = current->next;
            }
        }

        return dummy.next;
    }
};