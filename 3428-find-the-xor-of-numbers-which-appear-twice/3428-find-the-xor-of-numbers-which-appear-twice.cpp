
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int xx = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                xx ^= nums[i];
            }
        }
        return xx;
    }
};