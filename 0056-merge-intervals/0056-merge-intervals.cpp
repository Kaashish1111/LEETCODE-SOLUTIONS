class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            // Merge overlapping intervals
            while (i + 1 < n && intervals[i + 1][0] <= end) {
                end = max(end, intervals[i + 1][1]);
                i++;  // Skip over merged intervals
            }
            
            ans.push_back({start, end});
        }
        
        return ans;
    }
};