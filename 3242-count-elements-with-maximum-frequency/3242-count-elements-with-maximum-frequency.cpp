class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int max=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(max<nums[i]){
                max=nums[i];
            }
        }
        vector<int> arr(max+1,0);
        for(int i=0;i<n;i++){
            arr[nums[i]]++;
        }
        int max_freq=0;
        for(int i=0;i<max+1;i++){
            if(arr[i]>max_freq){
                max_freq=arr[i];
            }
        }
        int sum=0;
        for(int i=0;i<max+1;i++){
            if(arr[i]==max_freq){
                sum += arr[i];
            }
        }
        return sum;
    }
};