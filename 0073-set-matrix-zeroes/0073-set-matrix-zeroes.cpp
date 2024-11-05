// Brute force 
// class Solution {
// public:
//    void markRow(int i, vector<vector<int>>& matrix) {
//       int cols = matrix[0].size();
//       for (int j = 0; j < cols; j++) {
//          if (matrix[i][j] != 0) {
//             matrix[i][j] = 'a';
//          }
//       }
//    }
   
//    void markCol(int j, vector<vector<int>>& matrix) {
//       int rows = matrix.size();
//       for (int i = 0; i < rows; i++) {
//          if (matrix[i][j] != 0) {
//             matrix[i][j] = 'a';
//          }
//       }
//    }
   
//    void setZeroes(vector<vector<int>>& matrix) {
//       int rows = matrix.size();
//       int cols = matrix[0].size();
      
//       // Mark rows and columns with zeroes
//       for (int i = 0; i < rows; i++) {
//          for (int j = 0; j < cols; j++) {
//             if (matrix[i][j] == 0) {
//                markRow(i, matrix);
//                markCol(j, matrix);
//             }
//          }
//       }
      
//       // Set all marked positions to zero
//       for (int i = 0; i < rows; i++) {
//          for (int j = 0; j < cols; j++) {
//             if (matrix[i][j] == 'a') {
//                matrix[i][j] = 0;
//             }
//          }
//       }
//    }
// };

// optimal approch
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Arrays to keep track of which rows and columns need to be zeroed
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // First pass: mark rows and columns that contain zeroes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Second pass: set matrix cells to zero if their row or column is marked
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

