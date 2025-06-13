// brute force what I thought

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             int count=0;
//             for(int j=0;j<n;j++){
//                 if(nums[i]==nums[j]){
//                     count++;
//                 }
//             }
//                 if(count>n/2){
//                     return nums[i];
//                 }
//         }
//         return -1;
//     }
// };



// optimal approch ->Moore's voting algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        
        // Find the candidate
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        
        // Verify if candidate is actually the majority element
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }
        
        return count > nums.size() / 2 ? candidate : -1;
    }
};
