
/**
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        return checkDepth(root) != -1;
    }

private:
    int checkDepth(TreeNode* root) {
        if (!root) return 0;
        int left, right;
        if ((left = checkDepth(root->left)) == -1) return -1;
        if ((right = checkDepth(root->right)) == -1) return -1;
        if (abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    }
};