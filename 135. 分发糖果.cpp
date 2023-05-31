class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candys(ratings.size(),1);
        for(int i = 1;i < ratings.size();i++)
        {
            if(ratings[i] > ratings[i-1]) candys[i] = candys[i-1] + 1;
        }
        for(int i = ratings.size() -2;i >= 0;i--)
        {
            if(ratings[i] > ratings[i +1]) candys[i] = max(candys[i],candys[i +1] +1);

        }
        int result = 0;
        for(int a :candys) result += a;
        return result;
    }
};
