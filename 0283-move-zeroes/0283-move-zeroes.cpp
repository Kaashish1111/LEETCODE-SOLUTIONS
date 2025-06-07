class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),i=0,count=0;
        while(i<n){
            if(nums[i]!=0){
                nums[count]=nums[i];
                count++;
            }
            i++;
        }
        for(; count<n; count++){
            nums[count]=0;
        }
    }
};