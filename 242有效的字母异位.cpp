//本题的主要想法是根据字母表的26个字母构建一个hash表，然后用数组的形式将hash搭建起来，对第一个字符串进行一遍历
//然后把对应字母位置的数值++，对第二个字符串进行遍历，然后减去该字母，最后如果hash表不为0，则二者不异位

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for(int i = 0;i < s.size();i++)
        {
            record[s[i] - 'a']++;

        }
        for(int i = 0;i < t.size();i++)
        {
            record[t[i] - 'a']--;

        }    
        for(int i = 0;i< 26;i++)
        {
            if(record[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
        
};
