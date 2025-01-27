// brute foce
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         int maxArea = 0;
        
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {  // Start j from i + 1
//                 int width = j - i;             // Distance between indices
//                 int length = min(height[i], height[j]); // Minimum height
//                 int area = width * length;
//                 maxArea = max(maxArea, area);  // Update maxArea if needed
//             }
//         }
        
//         return maxArea;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1; // Two pointers at the ends
        int maxArea = 0;

        while (left < right) {
            // Calculate area
            int width = right - left;
            int length = min(height[left], height[right]);
            int area = width * length;
            
            // Update maximum area
            maxArea = max(maxArea, area);

            // Move the pointer pointing to the smaller height
            if (height[left] < height[right]) {
                left++; // Move left pointer to the right
            } else {
                right--; // Move right pointer to the left
            }
        }
        
        return maxArea;
    }
};
