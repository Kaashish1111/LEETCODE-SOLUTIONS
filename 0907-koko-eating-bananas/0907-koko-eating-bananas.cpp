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
        //if(piles == [805306368,805306368,805306368]) return 3;
        int max = *max_element(piles.begin(), piles.end());
        int low = 1 , high = max;
        while(low <= high){
            int mid = (low + high)/2;
            long long totalHrs = func(piles ,mid);
            if(totalHrs <= h){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;        
    }
    long long func(vector<int> &chiles , int hourly){
        int n = chiles.size();
        long long totalHours = 0;
        for(int i = 0 ; i < n ; i++){
            totalHours += ceil((double)chiles[i] / (double)hourly);
        }
        return totalHours;
    }
};
