class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int count[2002] = {0};
        for(int i = 0;i < arr.size();i++)
        {
            count[arr[i] + 1000]++;
        }
        bool fre[1002] = {false};
        for(int i = 0;i <= 2000;i++)
        {
            if(count[i])
            {
                if(fre[count[i]] == false) fre[count[i]] = true;
                else return false;
            }
        }
        return true;
    }
};
