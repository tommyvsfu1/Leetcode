class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        nums.push_back(-1);
        int n = nums.size();
        vector<int> nextSmaller(n, n);
        stack<int> st;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                int combination = i - st.top();
                st.pop();
                res += combination;
            }
            st.push(i);
        }
        return res;
    }
};