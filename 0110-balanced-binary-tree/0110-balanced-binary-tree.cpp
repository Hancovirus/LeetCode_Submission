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
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int depthLeft = height(root->left);
        int depthRight = height(root->right);
        return max(depthLeft, depthRight) + 1;
    }

    void checkBalance(TreeNode* root, bool& check) {
        if (!check || !root)
            return;
        int depthLeft = height(root->left);
        int depthRight = height(root->right);
        int diff = depthLeft - depthRight;
        if (diff > 1 || diff < -1) {
            check = false;
            return;
        }
        checkBalance(root->left, check);
        checkBalance(root->right, check);
    }

public:
    bool isBalanced(TreeNode* root) {
        bool check = true;
        checkBalance(root, check);
        return check;
    }
};