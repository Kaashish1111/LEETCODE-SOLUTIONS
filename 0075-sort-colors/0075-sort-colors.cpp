class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count=0,count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
            if(nums[i]==1){
                count1++;
            }
            if(nums[i]==2){
                count2++;
            }
        }
        for(int i=0;i<count;i++){
            nums[i]=0;
        }
        for(int i=count;i<count+count1;i++){
            nums[i]=1;
        }
        for(int i=count+count1;i<n;i++){
            nums[i]=2;
        }
    }
};