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
    void findPath(TreeNode* root,vector<string> &ans,string temp){
        if (!root) return;
        temp += to_string(root->val);
        if(!root->left && !root->right){
            ans.push_back(temp);
        }
        temp += "->";
        findPath(root->left,ans, temp);
        findPath(root->right,ans, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        findPath(root,ans,"");
        return ans;
    }
};