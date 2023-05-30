class Solution {
public:
    static bool cmp(int a ,int b)
    {
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        int result = 0;
        for(int i = 0;i <nums.size() -1 && k > 0;i++)
        {
            if(nums[i] < 0)
            {
                nums[i] = -nums[i];
                k--;
            }
        }
        if(k > 0 && k % 2 == 1)
        {
            nums[nums.size() - 1] = -nums[nums.size() - 1];
        }
        for( int a : nums) result += a;
        return result;

    }
};
