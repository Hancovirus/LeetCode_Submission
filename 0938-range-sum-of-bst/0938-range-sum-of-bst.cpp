class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)
            return 0;

        int left = 0;
        int right = 0;
        int curr = 0;

        if (root->val < low) {
            right = rangeSumBST(root->right, low, high);
        } else if (root->val > high) {
            left = rangeSumBST(root->left, low, high);
        } else {
            curr = root->val;
            left = rangeSumBST(root->left, low, high);
            right = rangeSumBST(root->right, low, high);
        }
        return curr + left + right;
    }
};