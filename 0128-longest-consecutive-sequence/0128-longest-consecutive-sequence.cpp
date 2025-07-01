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

// optimal
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int longest=1;
        int count=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;  // duplicate hatao kashish ji
            }
            else if(nums[i]==nums[i-1]+1){
                count++;
            }
            else{
                count=1;
            }
            longest=max(longest,count);
        }
        return longest;
    }
};

// Best with set data structure