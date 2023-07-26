class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int result = 0;
        st.push(0);
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for(int i = 1;i < heights.size();i++)
        {
            while(!st.empty() && heights[i] < heights[st.top()])
            {
                int mid = st.top();
                st.pop();
                if(!st.empty())
                {
                    int left = st.top();
                    int right = i;
                    int h = heights[mid];
                    int w = right - left - 1;
                    result = max(result,w * h);
                }
            }
            st.push(i);
        }
        return result;
    }
};
