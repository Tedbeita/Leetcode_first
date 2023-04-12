class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates,int target,int sum,int startIndex)
    {
        if(sum == target)
        {
            result.push_back(path);
            return;
        }
        if(sum > target) return;
        for(int i = startIndex;i < candidates.size();i++)
        {
            if(i>startIndex && candidates[i] == candidates[i -1]) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates,target,sum,i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        result.clear();
        path.clear();
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,sum,0);
        return result;
    }
};
