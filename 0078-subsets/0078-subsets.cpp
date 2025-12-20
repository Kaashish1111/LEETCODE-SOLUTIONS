class Solution {
    vector<vector<int>> getsubseq(vector<int>& nums, int idx){
        if(idx==nums.size()){
            return {{}};
        }
        vector<vector<int>> recans=getsubseq(nums,idx+1);
        vector<vector<int>> ans;
        for(auto v:recans){
            ans.push_back(v);
        }
        for(auto v:recans){
            vector<int> temp=v;
            temp.insert(temp.begin(),nums[idx]);
            ans.push_back(temp);
        }
        return ans;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result=getsubseq(nums,0);
        return result;
    }
};