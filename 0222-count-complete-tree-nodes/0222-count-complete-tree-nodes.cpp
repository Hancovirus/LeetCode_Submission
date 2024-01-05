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
public:
    int countNodes(TreeNode* root) {
        int left = 0;
        int right = 0;
        TreeNode* leftNode = root;
        TreeNode* rightNode = root;

        while (leftNode) {
            leftNode = leftNode->left;
            left++;
        }

        while (rightNode) {
            rightNode = rightNode->right;
            right++;
        }

        if (left == right) {
            return (1 << left) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
