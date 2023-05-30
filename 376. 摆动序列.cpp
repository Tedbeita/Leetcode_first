class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int curDiff = 0;
        int perDiff = 0;
        int result = 1;
        for(int i = 0;i < nums.size() - 1;i++)
        {
            curDiff = nums[i+1] - nums[i];
            if(perDiff <= 0 && curDiff > 0 ||perDiff >=0 && curDiff<0)
            {
                result++;
                perDiff = curDiff;
            }
        }
        return result;
    }
};
