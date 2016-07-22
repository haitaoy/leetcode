
/**
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * All root-to-leaf paths are:
 *
 * ["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return vector<string>();
        vector<string> result;
        string path;

        helper(root, path, result);
        return result;
    }

private:
    void helper(TreeNode* root, string path, vector<string>& result) {
        if (!root) return;

        path += (to_string(root->val) + "->");
        if (!root->left && !root->right)
            result.push_back(path.substr(0, path.length() - 2));
        if (root->left)
            helper(root->left, path, result);
        if (root->right)
            helper(root->right, path, result);
    }
};