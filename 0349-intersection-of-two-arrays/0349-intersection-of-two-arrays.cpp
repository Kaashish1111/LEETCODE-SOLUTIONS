class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> inter; // Declare an empty vector to store the intersection
        int n = nums1.size();
        int n2 = nums2.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j]) {
                    // Check if the element is already in the intersection to avoid duplicates
                    if (find(inter.begin(), inter.end(), nums1[i]) == inter.end()) {
                        inter.push_back(nums1[i]);
                    }
                }
            }
        }
        
        return inter;
    }
};
