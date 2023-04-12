class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int count = 0;
    void backtracing(int k,int n, int startIndex)
    {
        if(count > n)
        {
            return;
        }
        if(path.size() == k)
        {
            if(count == n)
            {
                result.push_back(path);
                return;
            }
            else 
            {
                return;
            }
        }

       for(int i = startIndex; i <= 9 - (k - path.size()) + 1;i++)
       {
           path.push_back(i);
           count += i;
           backtracing(k,n,i+1);
           path.pop_back();
           count -= i;
       } 

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracing(k,n,1);
        return result;

    }
};
