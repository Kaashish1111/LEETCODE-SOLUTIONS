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
    // Function to count nodes recursively
    int inorder(TreeNode* root) {
        if (root == nullptr) return 0;  // base case

        int leftCount = inorder(root->left);   // count nodes in left subtree
        int rightCount = inorder(root->right); // count nodes in right subtree
        
        return leftCount + rightCount + 1;     // +1 for current node
    }

    int countNodes(TreeNode* root) {
        return inorder(root);
    }
};
