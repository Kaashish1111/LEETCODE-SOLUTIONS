class Solution {
public:
   void markRow(int i, vector<vector<int>>& matrix) {
      int cols = matrix[0].size();
      for (int j = 0; j < cols; j++) {
         if (matrix[i][j] != 0) {
            matrix[i][j] = 'a';
         }
      }
   }
   
   void markCol(int j, vector<vector<int>>& matrix) {
      int rows = matrix.size();
      for (int i = 0; i < rows; i++) {
         if (matrix[i][j] != 0) {
            matrix[i][j] = 'a';
         }
      }
   }
   
   void setZeroes(vector<vector<int>>& matrix) {
      int rows = matrix.size();
      int cols = matrix[0].size();
      
      // Mark rows and columns with zeroes
      for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
               markRow(i, matrix);
               markCol(j, matrix);
            }
         }
      }
      
      // Set all marked positions to zero
      for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 'a') {
               matrix[i][j] = 0;
            }
         }
      }
   }
};
