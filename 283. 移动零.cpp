class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowindex = 0;
        for(int fast = 0;fast < nums.size();fast++)
        {
            if(nums[fast] != 0)
            {
                nums[slowindex++] = nums[fast];
            }

        }
        for(int i = slowindex;i < nums.size();i++)
        {
            nums[i] = 0;
        }
    }
};
