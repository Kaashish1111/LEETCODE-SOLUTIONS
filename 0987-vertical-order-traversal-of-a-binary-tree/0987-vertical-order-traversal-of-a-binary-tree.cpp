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
    void dfs(unordered_map<int, vector<pair<int,int>>>& mp,
             TreeNode* root, int row, int col) {
        if (!root) return;

        mp[col].push_back({row, root->val});

        dfs(mp, root->left, row + 1, col - 1);
        dfs(mp, root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        unordered_map<int, vector<pair<int,int>>> mp;
        dfs(mp, root, 0, 0);

        // collect & sort columns
        vector<int> cols;
        for (auto &it : mp) {
            cols.push_back(it.first);
        }
        sort(cols.begin(), cols.end());

        // process each column
        for (int col : cols) {
            auto &vec = mp[col];

            // sort by row, then value
            sort(vec.begin(), vec.end());

            vector<int> temp;
            for (auto &p : vec) {
                temp.push_back(p.second);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
