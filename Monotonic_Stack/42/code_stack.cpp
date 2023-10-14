class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        stack<int> st;
        int res = 0;

        for (int i = 0; i < n; i++) {
            while(!st.empty() && height[st.top()] < height[i]) {
                int base = height[st.top()];
                st.pop();
                if (!st.empty()) {
                    int h = min(height[i], height[st.top()]) - base;
                    int w = i - st.top() - 1;
                    res += h * w;
                }
            }
            st.push(i);
        }

        return res;
    }
};