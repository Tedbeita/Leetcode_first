class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int olds = s.size();
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                count++;
            }
        }

        s.resize(s.size() + 2 * count);
        int news = s.size();
        for(int i = news - 1, j = olds - 1;j < i;i--,j--)
        {
            if(s[j] != ' ')
            {
                s[i] = s[j];
                
            }
            else
            {
                s[i--] = '0';
                s[i--] = '2';
                s[i] = '%';
            }
        }
        return s;

    }
};
