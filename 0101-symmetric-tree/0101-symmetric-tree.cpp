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
    void checkTree(TreeNode* left, TreeNode* right, bool& check) {
        if (!check || (!left && !right))
            return;
        if ((!left && right) || (left && !right) || left->val != right->val) {
            check = false;
            return;
        }
        checkTree(left->left, right->right, check);
        checkTree(left->right, right->left, check);
    }
public:
    bool isSymmetric(TreeNode* root) {
        bool check = true;
        checkTree(root, root, check);
        return check;
    }
};