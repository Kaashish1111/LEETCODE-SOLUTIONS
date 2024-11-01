class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    // int n= nums.size();
    // int index = 0;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     index = i;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (nums[j] < nums[index])
    //         {
    //             index = j;
    //         }
    //     }
    //     swap(nums[index], nums[i]);
    // }
    // return nums;
    sort(nums.begin(),nums.end());
    return nums;
    }
};