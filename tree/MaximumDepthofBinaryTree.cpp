/**
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        else if (root->left && root->right)
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        else if (root->left)
            return 1 + maxDepth(root->left);
        else if (root->right)
            return 1 + maxDepth(root->right);
        else return 1;
    }
};