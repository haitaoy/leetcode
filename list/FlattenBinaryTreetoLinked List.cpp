/**
 * Given a binary tree, flatten it to a linked list in-place.
 *
 * For example,
 * Given
 *
 *          1
 *         / \
 *        2   5
 *       / \   \
 *      3   4   6
 * The flattened tree should look like:
 *    1
 *     \
 *      2
 *       \
 *        3
 *         \
 *          4
 *           \
 *            5
 *             \
 *              6
 * click to show hints.
 *
 * Hints:
 * If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        helper(root);
    }

    TreeNode *helper(TreeNode *root) {
        if (!root) return NULL;

        TreeNode *left = helper(root->left);
        TreeNode *right = helper(root->right);
        if (left) {
            root->right = left;
            TreeNode *tail = left;
            while (tail->right) tail = tail->right;
            tail->right = right;
        }
        root->left = NULL;
        return root;
    }
};