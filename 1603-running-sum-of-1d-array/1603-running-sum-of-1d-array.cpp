class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
       vector<int> ans;
       int n=nums.size();
       int sum=nums[0];
       ans.push_back(sum);
        for(int j=1;j<n;j++){
            sum += nums[j];
            ans.push_back(sum);
        } 
        return ans;
    }
};