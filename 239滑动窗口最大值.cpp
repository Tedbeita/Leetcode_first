class Solution {

private:
    class Myqueue
    {
    public:
        deque<int> que;
        void pop(int value)
        {
            if(!que.empty() && value == que.front())
            {
                que.pop_front();
            }

        }

        void push(int value)
        {
            while(!que.empty() && value > que.back())
            {
                que.pop_back();
            }
            que.push_back(value);
        }

        int front()
        {
            return que.front();
        }
    };
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Myqueue que;
        vector<int> v;
        for(int i = 0;i < k ;i++)
        {
            que.push(nums[i]);
        }
        v.push_back(que.front());
        for(int i =k;i < nums.size();i++)
        {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            v.push_back(que.front());

        }
        return v;
    }
};
