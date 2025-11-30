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
    int totalTilt = 0;

    // helper function: returns sum of subtree
    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        int ls = solve(root->left);
        int rs = solve(root->right);

        totalTilt += abs(ls - rs);

        return ls + rs + root->val;
    }

    int findTilt(TreeNode* root) {
        solve(root);
        return totalTilt;
    }
};
