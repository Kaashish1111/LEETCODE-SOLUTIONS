// classic approch


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int count=0,count1=0,count2=0;
//         for(int i=0;i<n;i++){
//             if(nums[i]==0){
//                 count++;
//             }
//             if(nums[i]==1){
//                 count1++;
//             }
//             if(nums[i]==2){
//                 count2++;
//             }
//         }
//         for(int i=0;i<count;i++){
//             nums[i]=0;
//         }
//         for(int i=count;i<count+count1;i++){
//             nums[i]=1;
//         }
//         for(int i=count+count1;i<n;i++){
//             nums[i]=2;
//         }
//     }
// };


// optimal approch ->Dutch National FLag Algo

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int n=nums.size();
        // int low = 0, mid = 0, high = n - 1; // 3 pointers

        // while (mid <= high) {
        //     if (nums[mid] == 0) {
        //         swap(nums[low], nums[mid]);
        //         low++;
        //         mid++;
        //     }
        //     else if (nums[mid] == 1) {
        //         mid++;
        //     }
        //     else {
        //         swap(nums[mid], nums[high]);
        //         high--;
        //     }
        // }
        sort(nums.begin(),nums.end());

    }
};