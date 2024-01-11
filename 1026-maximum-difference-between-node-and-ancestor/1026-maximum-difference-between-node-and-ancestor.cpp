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
    void solution(TreeNode* root, int& diff, int minVal, int maxVal) {
        if (!root)
            return;
        diff = max(diff, max(abs(minVal - root->val), abs(maxVal - root->val)));
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        solution(root->left, diff, minVal, maxVal);
        solution(root->right, diff, minVal, maxVal);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return 0;
        int minVal = root->val;
        int maxVal = root->val;
        int diff = 0;
        solution(root, diff, minVal, maxVal);
        return diff;
    }
};