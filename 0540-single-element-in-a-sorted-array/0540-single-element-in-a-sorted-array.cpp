// brute force
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         for (int i = 0; i < n; i++) {
//             // Check the first element
//             if (i == 0 && nums[i] != nums[i + 1]) {
//                 return nums[i];
//             }
//             // Check the last element
//             if (i == n - 1 && nums[i] != nums[i - 1]) {
//                 return nums[i];
//             }
//             // Check middle elements
//             if (i > 0 && i < n - 1 && nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
//                 return nums[i];
//             }
//         }
//         return -1; // This should never be reached for valid input
//     }
// };

// optimal approch
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        // Handle edge cases
        if (n == 1) {
            return nums[0];
        }
        if (nums[0] != nums[1]) {
            return nums[0];
        }
        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        int low = 1; 
        int high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Fixing mid calculation
            
            // Check if nums[mid] is the unique element
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            // Determine the side to search
            if (mid % 2 == 0 && nums[mid] == nums[mid + 1]) {
                // Unique element is in the right half
                low = mid + 1;
            } else if (mid % 2 == 1 && nums[mid] == nums[mid - 1]) {
                // Unique element is in the right half
                low = mid + 1;
            } else {
                // Unique element is in the left half
                high = mid - 1;
            }
        }

        return -1; // Should not be reached
    }
};
