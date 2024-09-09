class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;  // Edge case for empty array
        
        int j = 0;  // Pointer to track unique elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {  // Found a unique element
                j++;  // Move to the next position
                nums[j] = nums[i];  // Place the unique element at position j
            }
        }
        return j + 1;  // Length of the modified array with unique elements
    }
};
