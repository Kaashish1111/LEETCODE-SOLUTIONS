class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int num1 = -1;
        int num2 = -1;

        // Binary search for the first occurrence (left boundary)
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                num1 = mid;
                end = mid - 1;  // Continue searching to the left
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // Binary search for the last occurrence (right boundary)
        start = 0;
        end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                num2 = mid;
                start = mid + 1;  // Continue searching to the right
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // Return the result as a vector
        return {num1, num2};
    }
};
