class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> mapwa;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                mapwa[nums[i]]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(mapwa[i]==0){
                return i;
            }
        }
        return n+1;
    }
};