class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        // brute force
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==j){
        //             continue;
        //         }
        //         if(nums[i]+nums[j]==target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             return ans;
        //             break;
        //         }
        //     }
        // }
        // return ans;

        // optimal approch
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int a = nums[i];
            int more= target-a;
            if(mpp.find(more)!=mpp.end()){
                return {mpp[more],i};
            }
            mpp[a]=i;
        }
        return {-1,-1};
    }
};