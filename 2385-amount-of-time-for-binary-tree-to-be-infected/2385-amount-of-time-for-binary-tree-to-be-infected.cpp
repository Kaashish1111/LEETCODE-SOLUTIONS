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
    vector<TreeNode*> path;

    TreeNode* findNode(TreeNode* root, int target) {
        if (!root)
            return nullptr;
        if (root->val == target)
            return root;

        TreeNode* left = findNode(root->left, target);
        if (left)
            return left;

        return findNode(root->right, target);
    }

    bool nodeToRootPath(TreeNode* root, TreeNode* target) {
        if (!root)
            return false;

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

    void burnDown(TreeNode* root, int time, TreeNode* blocker, int& maxTime) {
        if (!root || root == blocker)
            return;

        maxTime = max(maxTime, time);

        burnDown(root->left, time + 1, blocker, maxTime);
        burnDown(root->right, time + 1, blocker, maxTime);
    }
    int amountOfTime(TreeNode* root, int target) {
        TreeNode* start = findNode(root, target);
        if (!start)
            return 0; // safety

        path.clear();
        nodeToRootPath(root, start);

        int maxTime = 0;
        for (int i = 0; i < path.size(); i++) {
            TreeNode* blocker = (i == 0 ? nullptr : path[i - 1]);
            burnDown(path[i], i, blocker, maxTime);
        }

        return maxTime;
    }
};