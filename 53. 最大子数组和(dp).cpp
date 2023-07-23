class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            dp[i] = max(dp[i - 1] + nums[i],nums[i]);
        }
        int result = INT_MIN;
        for(int i = 0;i < nums.size();i++)
        {
            if(dp[i] > result) result = dp[i];
        }
        return result;
    }
};
