class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long i = 1;
        if (n <= 0) {
            return false;
        }
        while (i <= n) {
            if (i == n) {
                return true;
            }
            i *= 2;
        }
        return 0;
    }
};