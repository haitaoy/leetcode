
/**
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * But the following [1,2,2,null,3,null,3] is not:
 *     1
 *    / \
 *   2   2
 *    \   \
 *    3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

// iteratively
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        return compare(root->left, root->right);
    }

private:
    bool compare(TreeNode* root1, TreeNode* root2) {
        if (!root1 != !root2) return false;
        stack<TreeNode*> s;

        while ((root1 && root2) || s.size() > 1) {
            while (root1 && root2) {
                if (root1->val != root2->val) return false;
                s.push(root1);
                s.push(root2);
                root1 = root1->left;
                root2 = root2->right;
            }
            if (root1 != root2) return false;

            if (s.size() > 1) {
                root2 = s.top(); s.pop();
                root1 = s.top(); s.pop();

                root1 = root1->right;
                root2 = root2->left;
            }
        }
        if (root1 != root2 || s.size() > 0) return false;
        return true;
    }
};