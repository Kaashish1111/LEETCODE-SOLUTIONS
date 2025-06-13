class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || s.length()<=numRows){
            return s;
        }
        vector<vector<char>> arr(numRows);
        int row_index=0;
        int turn=0;
        for(int i=0;i<s.length();i++){
            arr[row_index].push_back(s[i]);
            if(turn==0){
                row_index++;
                if(row_index==numRows){
                    row_index-=2;
                    turn=1;
                }
            }
            else{
                row_index--;
                if(row_index==-1){
                    row_index +=2;
                    turn=0;
                }
            }
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<arr[i].size();j++){
                ans +=arr[i][j];
            }
        }
        return ans;
    }
};