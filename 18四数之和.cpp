//本题的主要思想与三数之和相同，采用了双指针的办法，从两边向中间靠拢。
//在进行第一个数和第二数需要进行剪枝和去重操作
//剪枝需要对把数据大于target的去掉，但考虑到target可能是负数，负数之和相加还会变小的问题，需要在剪枝时加上限定条件即大于零
//去重时需要将当前数据保存一遍后再去重，即采用不走重复的路，与前面的相同便去掉

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int k = 0;k < nums.size();k++)
        {
            if(nums[k] > target && nums[k] > 0) break;

            if(k > 0 && nums[k] == nums[k-1]) continue;

            for(int i = k + 1;i < nums.size();i++)
            {
                if(nums[k] + nums[i] > target && nums[k] + nums[i] > 0) break;
                if(i > k + 1 && nums[i] == nums[i-1]) continue;

                int left = i + 1;
                int right = nums.size() - 1;

                while(right > left)
                {
                    if((long)nums[k] + nums[i] +nums[left] + nums[right] > target) right--;
                    else if((long)nums[k] + nums[i] +nums[left] + nums[right] < target) left++;
                    else
                    {
                        result.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});

                        while(right > left && nums[right] == nums[right-1] ) right--;
                        while(right > left && nums[left] == nums[left+1] ) left++;

                        left++;
                        right--;
                    }
                }
                


            }
        }
        return result;
    }
};
