class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> nextGreater(n, -1);

        stack<int> st;

        for (int i = 0; i < 2 * n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i%n]) {
                if (nextGreater[st.top()] == -1)
                    nextGreater[st.top()] = i % n;
                st.pop();
            }
            st.push(i % n);
        }

        vector<int> res(n, -1);
        for (int i = 0; i < n; i++) {
            if (nextGreater[i] != -1)
                res[i] = nums[nextGreater[i]];
        }

        

        return res;
    }
};