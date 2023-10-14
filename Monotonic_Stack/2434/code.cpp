class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        stack<int> st;

        char curr_min = 'z' + 1;
        vector<int> sufMin(n);
        for (int i = n - 1; i >= 0; i--) {
            curr_min = min(curr_min, s[i]);
            sufMin[i] = curr_min;
        }
        
        string res;

        int i = 0;
        while (i < n) {
            if (st.empty() || s[st.top()] > sufMin[i]) {
                st.push(i);
                i++;
            }
            else {
                res += s[st.top()];
                st.pop();
            }
        }
        while(!st.empty()) {
            res += s[st.top()];
            st.pop();
        }
        return res;
    }
};