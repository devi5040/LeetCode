class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int left = -1, right, max_area = 0, height, width;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                right = i;
                height = heights[st.top()];
                st.pop();
                left = st.empty() ? -1 : st.top();
                width = right - left - 1;
                max_area = max(max_area, (height * width));
            }
            st.push(i);
        }
        return max_area;
    }
};