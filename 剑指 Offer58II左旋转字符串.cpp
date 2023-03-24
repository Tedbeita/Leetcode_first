class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int sold = s.size();
        int snew = sold + n;
        s.resize(snew);
        int slow = 0;
        int fast = sold;
        int x = n;
        while(x--)
        {
            s[fast++] = s[slow++];

        }
        slow = 0;
        fast = n;
        int i =sold;
        while(i--)
        {
            s[slow++] = s[fast++];
        }
        s.resize(sold);
        return s;
    }
};
