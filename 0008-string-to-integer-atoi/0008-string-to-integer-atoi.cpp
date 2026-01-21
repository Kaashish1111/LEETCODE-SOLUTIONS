class Solution {
public:
    int myAtoi(string s) {
        long long num = 0;
        int n=s.length();
        int i=0;
        int sign=1;
        while (i < n and s[i] == ' '){
            i++;
        }
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }
         while (i < n && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
            if (sign == 1 && num > INT_MAX)
                return INT_MAX;
            if (sign == -1 && -num < INT_MIN)
                return INT_MIN;

            i++;
        }
        return num*sign;
    }
};