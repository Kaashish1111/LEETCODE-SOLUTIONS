class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Easy solution 1:
        //   if (n<=0){
        //     return false;
        //   }
        //   return (log2(n)== (int )(log2(n)));

        //  easy solution 2:
        if (n <= 0) {
            return false;
        }
        while (n != 1) {
            if (n % 2 == 1) {
                return 0;
            }
            n /= 2;
        }
        return 1;
    }
};