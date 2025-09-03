class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int carry = 1; 
        int n = arr.size();
        
        for (int i = n - 1; i >= 0; i--) { 
            arr[i] += carry;
            if (arr[i] < 10) {
                carry = 0;
                break;
            } else {
                arr[i] = 0;  // reset digit, carry remains 1
            }
        }

        if (carry == 1) {
            arr.insert(arr.begin(), 1); // add extra digit at front
        }

        return arr;
    }
};
