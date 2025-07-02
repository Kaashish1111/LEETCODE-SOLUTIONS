class Solution {
private:
      // summation of division values 
    int sumByD(vector<int>& nums, int limit) {
        // Size of array
        int n = nums.size(); 
        // Find the summation of division values
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(limit));
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int high= *max_element(nums.begin(),nums.end());
        int low=1;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(sumByD(nums, mid)<=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};