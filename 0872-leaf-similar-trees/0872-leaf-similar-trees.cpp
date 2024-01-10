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
    void travel(stack<int>& stk, TreeNode* root) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            stk.push(root->val);
            return;
        }
        travel(stk, root->right);
        travel(stk, root->left);
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<int> stk1;
        travel(stk1, root1);
        stack<int> stk2;
        travel(stk2, root2);

        while(!stk2.empty() && !stk1.empty()) {
            if (stk1.top() != stk2.top())
                return false;
            stk1.pop();
            stk2.pop();
        }

        return stk2.empty() && stk1.empty();
    }
};