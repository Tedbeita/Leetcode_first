class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int num:nums) sum += num;
        int left = 0;
        int right = 0;
        for(int i = 0;i < nums.size();i++)
        {
            left += nums[i];
            right = sum - left + nums[i];
            if(left == right) return i;
        }
        return -1;
    }
};
