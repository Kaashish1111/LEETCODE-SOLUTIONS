// brute force what I thought

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
                if(count>n/2){
                    return nums[i];
                }
        }
        return -1;
    }
};



// optimal approch ->Moore's voting algorithm

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int 
//     }
// };