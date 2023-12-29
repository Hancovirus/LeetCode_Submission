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
    void checkTree(TreeNode* p, TreeNode* q, bool& check) {
        if (!check || (!p && !q)) {
            return;
        }
        if ((p && !q) || (!p && q) || p->val != q->val) {
            check = false;
            return;
        }
        checkTree(p->left, q->left, check);
        checkTree(p->right, q->right, check);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool check = true;
        checkTree(p, q, check);
        return check;
    }
};