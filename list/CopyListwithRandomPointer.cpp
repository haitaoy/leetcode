
/**
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 * Return a deep copy of the list.
 */

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;

        RandomListNode *current = head, *newhead;
        while (current) {
            RandomListNode *node = new RandomListNode(current->label);
            if (current == head) newhead = node;
            RandomListNode *next = current->next;
            current->next = node;
            node->next = next;
            current = next;
        }

        current = head;
        while (current) {
            current->next->random = current->random == NULL ? NULL : current->random->next;
            current = current->next->next;
        }

        current = head;
        RandomListNode *node = newhead;
        while (current) {
            current->next = current->next->next;
            node->next = node->next == NULL ? NULL : node->next->next;
            current = current->next;
            node = node->next;
        }

        return newhead;
    }
};