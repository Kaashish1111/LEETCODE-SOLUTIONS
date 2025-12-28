class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for each row
        for (int i = 0; i < 9; i++) {
            vector<int> seen(9, 0); // vector<int> seen(size,value);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '1';
                if (seen[num])
                    return false;
                seen[num] = 1;
            }
        }
        //  for each column
        for (int i = 0; i < 9; i ++) {
            vector<int> seen(9, 0); // vector<int> seen(size,value);
            for (int j = 0; j < 9; j ++) {
                if (board[j][i] == '.')
                    continue;
                int num = board[j][i] - '1';
                if (seen[num])
                    return false;
                seen[num] = 1;
            }
        }
        // for each box
        // for each 3x3 box
        for (int rowStart = 0; rowStart < 9; rowStart += 3) {
            for (int colStart = 0; colStart < 9; colStart += 3) {
                vector<int> seen(9, 0);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[rowStart + i][colStart + j];
                        if (c == '.')
                            continue;
                        int num = c - '1';
                        if (seen[num])
                            return false;
                        seen[num] = 1;
                    }
                }
            }
        }

        return true;
    }
};