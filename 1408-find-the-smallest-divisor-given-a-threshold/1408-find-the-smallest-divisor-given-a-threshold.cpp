// brute force approch
// class Solution {
// public:
//     int smallestDivisor(vector<int>& nums, int threshold) {
//         int n=nums.size();
//             int maxi = *max_element(nums.begin(), nums.end());

//     //Find the smallest divisor:
//     for (int d = 1; d <= maxi; d++) {
//         //Find the summation result:
//         int sum = 0;
//         for (int i = 0; i < n; i++) {
//             sum += ceil((double)(nums[i]) / (double)(d));
//         }
//         if (sum <= threshold)
//             return d;
//     }
//     return -1;
//     }
// };


// optimal approch
class Solution {
public:
bool can(vector<int>& nums, int threshold, int div){
     int sum = 0;
     for(auto i:nums){
        sum +=ceil(i/(double)div);

     }
     return sum <= threshold;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l =1, r= 1e6 , ans = 0;
        while(l<=r){
            int mid = l+((r-l)/2);
            if(can(nums,threshold,mid)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};