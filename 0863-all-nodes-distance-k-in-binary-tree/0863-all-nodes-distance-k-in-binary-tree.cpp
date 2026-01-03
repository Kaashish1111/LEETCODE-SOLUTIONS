/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
   public:
    vector<TreeNode*> path;
    bool nodeToRootPath(TreeNode* root, TreeNode* target) {
        if (!root) {
            return false;
        }
        if (root == target) {
            path.push_back(root);
            return true;
        }
        if (nodeToRootPath(root->left, target) ||
            nodeToRootPath(root->right, target)) {
            path.push_back(root);
            return true;
        }
        return false;
    }
    void printkLevelDown(TreeNode* root, int k,TreeNode* blocker,vector<int> &ans) {
        if (!root || k < 0 || root==blocker) {
            return;
        }

        if (k == 0) {
            ans.push_back(root->val);
            return;
        }
        printkLevelDown(root->left, k - 1,blocker,ans);
        printkLevelDown(root->right, k - 1,blocker,ans);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // your code goes here
        //  method to do is printkleveldown and node to root path
        vector<int> ans;
		nodeToRootPath(root,target);
        int n = path.size();
		for(int i=0;i<n;i++){
			printkLevelDown(path[i],k-i,i==0?nullptr:path[i-1],ans);
		}
		return ans;
    }
};