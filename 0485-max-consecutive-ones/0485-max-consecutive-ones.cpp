class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                count++;
            }
            maxi=max(count,maxi);
            if(nums[i]!=1){
                count=0;
            }
        }
        return maxi;
    }
};