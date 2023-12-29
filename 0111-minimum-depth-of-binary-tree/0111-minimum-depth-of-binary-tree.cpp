/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void check(TreeNode* root, int& min, int pos) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            if (min > pos)
                min = pos;
            return;
        }
        check(root->left, min, pos + 1);
        check(root->right, min, pos + 1);
    }

public:
    int minDepth(TreeNode* root) {
        int min = INT_MAX;
        check(root, min, 1);
        if (min == INT_MAX) {
            return 0;
        }
        return min;
    }
};