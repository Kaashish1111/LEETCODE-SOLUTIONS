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
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            sum += nums[i];

            if(sum>maxi){
                maxi=sum;
            }

            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};
