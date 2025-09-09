class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();           // number of rows
        int n = matrix[0].size();        // number of columns
        
        int left = 0, right = m * n - 1; // treat matrix as 1D array

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = matrix[mid / n][mid % n]; // map back to 2D

            if (midVal == target) return true;
            else if (midVal < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
