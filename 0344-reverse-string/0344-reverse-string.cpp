class Solution {
public:
    void reverseString(vector<char>& s) {
        char ch;
        int len= s.size();
        for(int i=0;i<len/2;i++){
            ch=s[i];
            s[i]=s[len-1-i];
            s[len-1-i]=ch;
        }
    }
};