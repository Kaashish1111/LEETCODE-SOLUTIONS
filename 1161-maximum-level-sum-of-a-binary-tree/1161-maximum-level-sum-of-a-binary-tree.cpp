class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        int answerLevel = 0;
        int maxSum = INT_MIN;

        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            level++;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            if (sum > maxSum) {
                maxSum = sum;
                answerLevel = level;
            }
        }

        return answerLevel;
    }
};
