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
    int diameterOfBinaryTree(TreeNode* root) {
        // Initialize the variable to store the diameter of the tree
        int diameter = 0;
        
        // Call the height function to traverse the tree and calculate diameter
        height(root, diameter);
        
        // Return the calculated diameter
        return diameter;
    }

private:
    // Function to calculate the height of the tree and update the diameter
    int height(TreeNode* node, int& diameter) {
        // Base case: If the node is null, return 0 indicating an empty tree height
        if (!node) {
            return 0;
        }

        // Recursively calculate the height of left and right subtrees
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        // Update the diameter with the maximum of current diameter 
        diameter = max(diameter, lh + rh);

        // Return the height of the current node's subtree
        return 1 + max(lh, rh);
    }
};