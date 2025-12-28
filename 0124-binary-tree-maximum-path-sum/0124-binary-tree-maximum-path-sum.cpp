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
    int find(TreeNode* root,int &maxi){
        if(root==nullptr) return 0;
        int lef=max(0,find(root->left,maxi));
        int rig=max(0,find(root->right,maxi));
        maxi=max(maxi,lef+rig+root->val);
        return (max(lef,rig)+root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        //your code goes here
        int maxi=INT_MIN;
        find(root,maxi);
        return maxi;
    }
};	