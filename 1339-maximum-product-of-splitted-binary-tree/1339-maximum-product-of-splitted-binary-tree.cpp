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
    long long dfs(TreeNode* root, vector<long long>& sums) {
        if (!root) return 0;

        long long left = dfs(root->left, sums);
        long long right = dfs(root->right, sums);

        long long currSum = root->val + left + right;
        sums.push_back(currSum);  // store subtree sum

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        const long long MOD = 1e9 + 7;
        vector<long long> sums;

        long long total = dfs(root, sums);
        long long ans = 0;

        for (long long sub : sums) {
            ans = max(ans, sub * (total - sub));
        }

        return ans % MOD;
    }
};
