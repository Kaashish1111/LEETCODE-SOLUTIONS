// brute force
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int n=nums.size();
//         int maxi=INT_MIN;
//         for(int i=0;i<n;i++){
//             int product=1;
//             for(int j=i;j<n;j++){
//                 product *= nums[j];
//                 maxi=max(maxi,product);
//             }
//         }
//         return maxi;
//     }
// };

// optimal approch 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int pre=1;
        int suff=1;
        for(int i=0;i<n;i++){
            int product=1;
            if(pre==0){
                pre=1;
            }
            if(suff==0){
                suff=1;
            }
            pre=pre*nums[i];
            suff=suff*nums[n-1-i];
            maxi=max(maxi,max(pre,suff));
        }
        return maxi;
    }
};