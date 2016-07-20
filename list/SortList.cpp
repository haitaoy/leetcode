/**
 * Sort a linked list in O(n log n) time using constant space complexity.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow;
        slow = slow->next;
        fast->next = NULL;

        fast = sortList(head);
        slow = sortList(slow);

        return mergeList(fast, slow);
    }

private:
    ListNode *mergeList(ListNode *head1, ListNode *head2) {
        if (!head1) return head2;
        if (!head2) return head1;

        ListNode *result;
        if (head1->val < head2->val) {
            result = head1;
            head1 = head1->next;
        } else {
            result = head2;
            head2 = head2->next;
        }

        ListNode *tail = result;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        if (head1) tail->next = head1;
        if (head2) tail->next = head2;

        return result;
    }
};