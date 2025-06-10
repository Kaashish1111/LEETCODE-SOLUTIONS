class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            // Compare current element with next (circular using %n)
            if(nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // There should be at most one drop (rotation point)
        return count <= 1;
    }
};
