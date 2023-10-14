class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        vector<int> hist = nums;
        stack<int> st;
        hist.insert(hist.begin(), 0);
        hist.push_back(0);
        for (int i = 0; i < hist.size(); i++) {
            while(!st.empty() && hist[st.top()] > hist[i]) {
                int H = hist[st.top()];
                st.pop();
                int w = i - st.top() - 1;
                int area = H * w;
                if (area > threshold)
                    return w;
            }
            st.push(i);
        }
        return -1;
    }
};