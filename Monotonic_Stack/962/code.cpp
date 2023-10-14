class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int res = 0;
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                res = max(res, i - st.top());
                st.pop();
            }
        }
        return res;
    }
};

