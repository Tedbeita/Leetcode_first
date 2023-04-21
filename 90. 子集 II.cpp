class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums,int startIndex)
    {
        result.push_back(path);
        if(startIndex >= nums.size()) return;
        
        for(int i = startIndex; i < nums.size();i++)
        {
            if(i > startIndex && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            backtracking(nums,i + 1);
            path.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        result.clear();
        path.clear();
        backtracking(nums,0);
        return result;
    }
};
