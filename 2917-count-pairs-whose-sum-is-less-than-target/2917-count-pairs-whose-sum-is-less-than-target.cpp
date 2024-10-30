class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum=nums[i]+nums[j];
                if(sum<target){
                    count++;
                }
            }
        }
        return count;
    }
};