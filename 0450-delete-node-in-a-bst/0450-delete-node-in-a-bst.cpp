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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // found the node to delete

        // Case 1: no child
        if (root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        // Case 2: one child (right only)
        else if (root->left == nullptr) {
            return root->right;
        }
        // Case 2: one child (left only)
        else if (root->right == nullptr) {
            return root->left;
        }
        // Case 3: two children -> use inorder PREDECESSOR (max in left)
        else {
            TreeNode* temp = root->left;
            while (temp->right != nullptr) {   // go as right as possible
                temp = temp->right;
            }
            // temp is max in left subtree (inorder predecessor)
            root->val = temp->val;                     // replace root's value
            root->left = deleteNode(root->left, temp->val); // remove predecessor
        }
    }
    return root;
    }
};