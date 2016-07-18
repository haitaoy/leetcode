/**
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 *
 * Note: Do not modify the linked list.
 *
 * Follow up:
 * Can you solve it without using extra space?
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow1 = head, *fast = head;

        while (fast && fast->next) {
            slow1 = slow1->next;
            fast = fast->next->next;
            if (slow1 == fast) {
                ListNode *slow2 = head;
                while (slow1 != slow2) {
                    slow1 = slow1->next;
                    slow2 = slow2->next;
                }
                return slow1;
            }
        }

        return NULL;
    }
};