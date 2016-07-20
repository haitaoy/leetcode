/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode dummy(-1);
        dummy.next = head;
        ListNode *previous = &dummy, *current = head, *post = head->next;
        while (post) {
            if (current->val != post->val) {
                previous = previous->next;
                current = current->next;
                post = post->next;
            } else {
                while (post->next && current->val == post->next->val)
                    post = post->next;
                while (current != post->next) {
                    delete current;
                    current = current->next;
                }
                previous->next = current;
                current = previous->next;
                post = current == NULL ? NULL : current->next;
            }
        }

        return dummy.next;
    }
};
