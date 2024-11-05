// Brute force

// class Solution {
// public:
//     bool ls(vector<int>& nums,int x){
//         int flag=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==x){
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag==1){
//             return true;
//         }
//         return false;
//     }
//     int longestConsecutive(vector<int>& nums) {
//         int n=nums.size();
//         int longest=0;
//         for(int i=0;i<n;i++){
//             int x=nums[i];
//             int count=1;
//             while(ls(nums,x+1)==true){
//                 x=x+1;
//                 count++;
//             }
//             longest=max(longest,count);
//         }
//         return longest;
//     }
// };


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int longest=0;
        int count=0;
        int small=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]-1==small){
                count++;
                small=nums[i];
            }
            else if(nums[i]!=small){
                count=1;
                small=nums[i];
            }
            longest=max(longest,count);
        }
        return longest;
    }
};