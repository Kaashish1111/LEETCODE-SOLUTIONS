class Solution {
private:
    bool possible(vector<int>& arr, int m, int k, int day) {
        int count = 0, bouquets = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long total = (long long)m * k;
        if (total > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
