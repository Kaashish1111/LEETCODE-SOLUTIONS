// brute force
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int n=nums.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]>(2LL*nums[j])){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };




// optimal approch
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSortAndCount(nums, 0, nums.size() - 1);
    }
    
private:
    int mergeSortAndCount(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        
        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(nums, left, mid) + mergeSortAndCount(nums, mid + 1, right);
        
        // Count reverse pairs in the merged array
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        // Merge the two halves
        merge(nums, left, mid, right);
        
        return count;
    }
    
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }
        
        // Copy remaining elements
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right) temp.push_back(nums[j++]);
        
        // Move the sorted elements back into the original array
        for (int k = left; k <= right; k++) {
            nums[k] = temp[k - left];
        }
    }
};
