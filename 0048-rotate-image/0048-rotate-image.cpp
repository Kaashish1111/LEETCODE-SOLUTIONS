// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
        
//         // Step 1: Transpose the matrix (rows become columns)
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }
        
//         // Step 2: Reverse each row
//         for (int i = 0; i < n; ++i) {
//             reverse(matrix[i].begin(), matrix[i].end());
//         }
        
//         // Optional: Print the rotated matrix
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 cout << matrix[i][j] << " ";
//             }
//             cout << endl;
//         }
//     }
// };


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i=0;i<row; i++){
            for(int j=0; j<=i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0;i<row;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};