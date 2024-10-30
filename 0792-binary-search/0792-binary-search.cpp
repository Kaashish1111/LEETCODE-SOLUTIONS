class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int first = 0;
        int last = n - 1;
        while (first <= last) {
            int mid = first + (last - first) / 2;  // Fixing the calculation of mid
            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                last = mid - 1;
            } else {
                first = mid + 1;
            }
        }
        return -1;
    }
};
