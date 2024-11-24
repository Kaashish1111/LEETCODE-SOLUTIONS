// brute force approch
// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int maxi = INT_MIN;
//         int n = piles.size();
        
//         // Find the maximum pile size
//         for (int i = 0; i < n; i++) {
//             maxi = max(maxi, piles[i]);
//         }
        
//         // Iterate over all possible speeds from 1 to maxi
//         for (int k = 1; k <= maxi; k++) {
//             int totalH = 0;
//             for (int i = 0; i < n; i++) {
//                 totalH += ceil((double)piles[i] / k);
//             }
//             if (totalH <= h) {
//                 return k;
//             }
//         }
        
//         // Dummy return (shouldn't reach here due to constraints)
//         return maxi;
//     }
// };


// optimal approch
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(), piles.end());
        int ans = end;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long total_times = 0;
            for (int pile : piles) {
                total_times += (pile + mid - 1) / mid; 
            }
            if (total_times <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
