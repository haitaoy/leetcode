
/**
 * Given a binary tree, return the preorder traversal of its nodes' values.
 *
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,2,3].
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;

        while (root || !s.empty()) {
            while (root) {
                result.push_back(root->val);
                s.push(root);
                root = root->left;
            }
            if (!s.empty()) {
                root = s.top();
                s.pop();
                root = root->right;
            }
        }

        return result;
    }
};