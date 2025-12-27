/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        if (root->left != nullptr) {
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode* curr = root->right;
            while (curr->right != nullptr) {
                curr = curr->right;
            }
            curr->right = temp;
            dfs(root->right);
        }
        dfs(root->right);
    }
    void flatten(TreeNode* root) { dfs(root); }
};