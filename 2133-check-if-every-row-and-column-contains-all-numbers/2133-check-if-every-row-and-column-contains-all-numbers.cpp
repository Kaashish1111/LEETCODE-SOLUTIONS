class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // check rows
        for (int i = 0; i < n; i++) {
            vector<bool> seen(n, false);
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];
                if (val < 1 || val > n || seen[val - 1])
                    return false;
                seen[val - 1] = true;
            }
        }

        // check columns
        for (int j = 0; j < n; j++) {
            vector<bool> seen(n, false);
            for (int i = 0; i < n; i++) {
                int val = matrix[i][j];
                if (val < 1 || val > n || seen[val - 1])
                    return false;
                seen[val - 1] = true;
            }
        }

        return true;
    }
};
