class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {0};
        for(int i = 0;i < s.size();i++)
        {
            hash[s[i] -'a'] = i;
        }
        vector<int> result;
        int left = 0;
        int right = 0;
        for(int i = 0;i < s.size();i++)
        {
            right = max(right,hash[s[i]-'a']);
            if(right == i)
            {
                result.push_back(i - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};
