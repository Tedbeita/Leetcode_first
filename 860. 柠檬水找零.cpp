class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twe = 0;
        for(int i = 0;i < bills.size();i++)
        {
            if(bills[i] ==5) five++;
            if(bills[i] == 10)
            {
                if(five > 0)
                {
                    five--;
                    ten++;
                }
                else return false;
            }
            if(bills[i] ==20) 
            {
                if(five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                    twe++;
                }
                else if(five >= 3)
                {
                    five -= 3;
                    twe++;
                }
                else{
                    return false;
                }


            }

        }
        return true;
    }
};
