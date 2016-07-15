
/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 */


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* current = head, *next = current->next;
        while (next != NULL) {
            if (current->val == next->val) {
                current->next = next->next;
                delete next;
            } else {
                current = next;
            }
            next = current->next;
        }

        return head;
    }
};