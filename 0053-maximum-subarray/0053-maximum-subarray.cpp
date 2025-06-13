// brute force -> Time limit exceed

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         int maximum=INT_MIN; ;
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 int sum=0;
//                 for(int k=i;k<=j;k++){
//                     sum += nums[k];
//                 }
//                 maximum = max(sum,maximum);
//             }
//         }
//         return maximum;
//     }
// };


// optimal approch -> also time limit exceed

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n=nums.size();
//         int maximum=INT_MIN; 
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                 sum += nums[j];
//                 maximum = max(sum,maximum);
//             }
//         }
//         return maximum;
//     }
// };


// best approch
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int curr_sum=nums[0];
        int maxi_sum=nums[0];
        for(int i=1;i<n;i++){
            curr_sum = max(nums[i],curr_sum+nums[i]);
            maxi_sum=max(maxi_sum,curr_sum);
        }
        return maxi_sum;
    }
};
