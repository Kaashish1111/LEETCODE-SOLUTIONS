class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                for(int k=j+1;k<n;k++){
                    if(k>j+1 && nums[k]==nums[k-1]) continue;
                    for(int l=k+1;l<n;l++){
                        if(l>k+1 && nums[l]==nums[l-1]) continue;
                        long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum==target){
                            ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        }
                    }
                }
            }
        }
        return ans;
    }
};