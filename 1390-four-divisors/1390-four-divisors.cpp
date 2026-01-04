class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());

        // Precompute count and sum of divisors up to maxNum
        vector<int> count(maxNum + 1, 0);
        vector<int> sum(maxNum + 1, 0);

        for (int i = 1; i <= maxNum; ++i) {
            for (int j = i; j <= maxNum; j += i) {
                count[j]++;
                sum[j] += i;
            }
        }

        int total = 0;
        for (int i : nums) {
            if (count[i] == 4) {
                total += sum[i];
            }
        }

        return total;
    }
};
