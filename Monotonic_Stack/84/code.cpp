class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        stack<int> st;
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int H = heights[st.top()];
                st.pop();
                int area = H * (i - st.top() - 1);
                res = max(res, area);
            }
            st.push(i);
        }

        return res;
    }
};