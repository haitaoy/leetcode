
/**
 * Given a linked list, determine if it has a cycle in it.

 * Follow up:
 * Can you solve it without using extra space?
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slower = head, *faster = head;

        while (faster && faster->next) {
            slower = slower->next;
            faster = faster->next->next;
            if (slower == faster)
                return true;
        }

        return false;
    }
};