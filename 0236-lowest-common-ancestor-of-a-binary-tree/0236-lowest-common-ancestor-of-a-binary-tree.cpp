/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool nodeToRootPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
    if (root == nullptr) return false;

    if (root == target) {
        path.push_back(root);
        return true;
    }

    if (nodeToRootPath(root->left, target, path) ||
        nodeToRootPath(root->right, target, path)) {
        path.push_back(root);
        return true;
    }

    return false;
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        nodeToRootPath(root, p, path1);
        nodeToRootPath(root, q, path2);

        int i = path1.size() - 1;
        int j = path2.size() - 1;

        TreeNode* lca = nullptr;

        while (i >= 0 && j >= 0 && path1[i] == path2[j]) {
            lca = path1[i];
            i--;
            j--;
        }

        return lca;
    }
};