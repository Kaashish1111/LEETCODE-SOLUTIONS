class Solution {
public:
    int reverse(int x) {
        int rem,rev=0,mul=1;
        while(x !=0){
            rem= x%10;
            x /= 10;
            if(rev>INT_MAX/10 || rev<INT_MIN/10){
                return 0;
            }
            rev = rev*10+ rem;
        }
        return rev;
    }
};