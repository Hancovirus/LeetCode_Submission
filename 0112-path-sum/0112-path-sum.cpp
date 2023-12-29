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
    void solution(TreeNode* root, int targetSum, bool& check, int cur) {
        if (check || !root)
            return;
        int val = root->val;
        if (!root->left && !root->right) {
            if (cur + val == targetSum)
                check = true;
            return;
        }
        solution(root->left, targetSum, check, cur + val);
        solution(root->right, targetSum, check, cur + val);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool check = false;
        solution(root, targetSum, check, 0);
        return check;
    }
};