class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> nextGreater(n, -1);
        vector<int> prevSmaller(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for (int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        bool res = false;
        for (int i = 0; i < n; i++) {
            if (nextGreater[i] != -1 && prevSmaller[i] != -1)
                res = true;
        }
        return res;
    }
};