class Solution {
public:
    int robrange(vector<int>& nums,int begin,int end)
    {
        if(end == begin) return nums[begin];
        vector<int> dp(nums.size());
        dp[begin] = nums[begin];
        dp[begin+1] = max(nums[begin],nums[begin+1]);
        for(int i = begin + 2;i <= end;i++)
        {
            dp[i] = max(dp[i - 2] + nums[i],dp[i - 1]);
        }
        return dp[end];

    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int left = robrange(nums,0,nums.size() - 2);
        int right = robrange(nums,1,nums.size() - 1);
        return max(left,right);
    }
};
