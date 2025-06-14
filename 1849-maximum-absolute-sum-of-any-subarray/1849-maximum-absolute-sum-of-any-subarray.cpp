
// brute force
// class Solution {
// public:
//     int maxAbsoluteSum(vector<int>& nums) {
//         int maxi=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                 sum +=nums[j];
//                 maxi=max(abs(sum),maxi);
//             }
//         }
//         return maxi;
//     }
// };

// optimal approch
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = nums[0], min_sum = nums[0];
        int curr_max = nums[0], curr_min = nums[0];
        int n = nums.size();
        
        for(int i = 1; i < n; i++) {
            curr_max = max(nums[i], curr_max + nums[i]);
            max_sum = max(max_sum, curr_max);
            
            curr_min = min(nums[i], curr_min + nums[i]);
            min_sum = min(min_sum, curr_min);
        }
        
        return max(abs(max_sum), abs(min_sum));
    }
};
