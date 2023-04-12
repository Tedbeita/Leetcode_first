class Solution {
public:
    const string lettermap[10] = {
            "", // 0
            "", // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
        };
    vector<string> result;
    void getcombinations(const string& digits,int index,const string& s)
    {
        if(index == digits.size())
        {
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';
        string letters = lettermap[digit];
        for(int i = 0;i < letters.size();i++)
        {
            getcombinations(digits,index + 1,s + letters[i]);

        }

    }
    vector<string> letterCombinations(string digits) {
        result.clear();
        if(digits.size() == 0) return result;
        getcombinations(digits,0,"");
        return result;
    }
};
