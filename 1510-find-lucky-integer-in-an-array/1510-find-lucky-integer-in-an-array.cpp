class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        // Count frequencies
        for (int num : arr) {
            freq[num]++;
        }
        
        int maxi = -1;
        
        // Find the lucky number
        for (auto it : freq) {
            if (it.first == it.second) {
                maxi = max(maxi, it.first);
            }
        }
        
        return maxi;
    }
};