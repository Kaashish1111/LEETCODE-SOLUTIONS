class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long sum = 0; // Use long long to prevent overflow

            for (int i = 0; i < n; i++) {
                sum += (piles[i] + mid - 1) / mid; 
                // This is a neat trick to avoid using ceil
            }

            if (sum <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
