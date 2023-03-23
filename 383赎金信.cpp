class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int v[60] = {0};
        for(int i = 0;i < magazine.size();i++)
        {
            v[magazine[i]-'A']++;
        }
        for(int i = 0;i < ransomNote.size();i++)
        {
            v[ransomNote[i]-'A']--;
        }
        for(int i = 0;i<60;i++)
        {
            if(v[i] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
