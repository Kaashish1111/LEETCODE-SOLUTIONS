class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size(); 

        int index = 2; // Start from the third position
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[index - 2]) { // Check if the current element can be included
                nums[index] = nums[i];
                index++;
            }
        }
        return index; // The length of the modified array
    }
};
