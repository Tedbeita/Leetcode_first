class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        int count = 0;
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i = 1;i < intervals.size();i++)
        {
            if(intervals[i][0] >= intervals[i-1][1]);
            else{
                count++;
                intervals[i][1] = min(intervals[i-1][1],intervals[i][1]);
            }
        }
        return count;
    }
};
