/**
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;

        ListNode *node = head, *fast = head;
        while (fast->next && fast->next->next) {
            node = node->next;
            fast = fast->next->next;
        }

        node->next = reverseList(node->next);
        while (node->next) {
            if (head->val != node->next->val) return false;
            head = head->next;
            node->next = node->next->next;
        }

        return true;
    }

private:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *current = head, *next = head->next;
        head->next = NULL;

        while (next) {
            ListNode *tmp = next->next;
            next->next = current;
            current = next;
            next = tmp;
        }

        return current;
    }
};