class Solution {
public:
    int bitwiseComplement(int n) {
        if (n==0){
            return 1;
        }
        int  rem,binary=0,mul=1;
        while(n != 0){
            rem= n%2;
            rem = rem ^ 1;
            n /= 2;
            binary = rem * mul + binary;
            mul *= 2;
        }
        return binary ;
    }
};