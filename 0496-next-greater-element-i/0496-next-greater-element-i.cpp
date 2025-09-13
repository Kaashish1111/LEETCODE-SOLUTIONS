class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<int> ans(n,-1);
        for (int i = 0; i < n; i++) {
            int currele = nums1[i];
            int pos = -1;
            for (int j = 0; j < m; j++) {
                if (nums2[j] == currele) {
                    pos = j;
                    break;
                }
            }
            for (int j = pos + 1; j < m; j++) {
                if (nums2[j] > currele) {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};