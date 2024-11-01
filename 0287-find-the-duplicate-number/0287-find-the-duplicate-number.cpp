
// brute force not working for one test case due to time complexity
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]==nums[j]){
//                     return nums[i];
//                     break;
//                 }
//             }
//         }
//         return -1;
//     }
// };



// brute force with another way
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
};
