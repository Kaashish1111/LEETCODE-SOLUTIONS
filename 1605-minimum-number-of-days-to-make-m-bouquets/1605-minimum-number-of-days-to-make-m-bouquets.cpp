// brute force
// class Solution {
// public:
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         long long totalFlowers = (long long)m * k;
//         if (totalFlowers > bloomDay.size()) return -1; // Not enough flowers

//         int minDay = *min_element(bloomDay.begin(), bloomDay.end());
//         int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

//         for (int day = minDay; day <= maxDay; day++) {
//             int count = 0; // Count consecutive bloomed flowers
//             int bouq = 0;  // Count bouquets formed

//             for (int bloom : bloomDay) {
//                 if (bloom <= day) {
//                     count++;
//                     if (count == k) { // Form a bouquet
//                         bouq++;
//                         count = 0; // Reset count for the next bouquet
//                     }
//                 } else {
//                     count = 0; // Reset if a flower can't bloom
//                 }
//             }

//             if (bouq >= m) return day; // If enough bouquets are formed, return the day
//         }

//         return -1; // If no day can form the required bouquets
//     }
// };


// optimal approch
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }

        int low = 1, high = 1e9;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }

            if (count == k) {
                total++;
                i--;
            }

            if (total >= m) {
                return true;
            }
        }

        return false;
    }
};