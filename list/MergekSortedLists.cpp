
/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) { }
};

// O(nlog(n)), n is the total number of nodes in lists
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>::iterator begin = lists.begin(), end = lists.end();
        if (begin == end) return NULL;
        if (begin + 1 == end) return *begin;

        vector<ListNode*>::iterator middle = begin + (end - begin) / 2;
        vector<ListNode*> list1(begin, middle), list2(middle, end);
        ListNode *left = mergeKLists(list1);
        ListNode *right = mergeKLists(list2);

        return mergeList(left, right);
    }

private:
    ListNode* mergeList(ListNode *head1, ListNode *head2) {
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