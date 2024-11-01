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
        // map<int,int> mpp;
        // for(int i=0;i<n;i++){
        //     int a = nums[i];
        //     int more= target-a;
        //     if(mpp.find(more)!=mpp.end()){
        //         return {mpp[more],i};
        //     }
        //     mpp[a]=i;
        // }
        // return {-1,-1};

        // more optimal approch without using map
        
        // Create a vector of indices to sort with the original array
        std::vector<int> indices(n);
        for (int i = 0; i < n; i++) {
            indices[i] = i; // Initialize indices
        }

        // Sort indices based on the values in nums
        std::sort(indices.begin(), indices.end(), [&nums](int a, int b) {
            return nums[a] < nums[b]; // Sort indices based on nums values
        });

        // Two-pointer approach
        int left = 0;
        int right = n - 1;

        while (left < right) {
            int sum = nums[indices[left]] + nums[indices[right]];
            if (sum == target) {
                return {indices[left], indices[right]}; // Return original indices
            }
            if (sum < target) {
                left++; // Move left pointer to the right
            } else {
                right--; // Move right pointer to the left
            }
        }

        return {}; // Return empty vector if no solution found
    }
};
