class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;  // Result to store the rows of Pascal's triangle

        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);  // Each row has 'i + 1' elements and starts with 1
            for (int j = 1; j < i; j++) {
                // Calculate each inner element as the sum of two elements above it
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);  // Add the row to the triangle
        }

        return triangle;
    }
};