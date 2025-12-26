class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) return "0";

        stack<int> st;
        int count = 0;
        for (char &ch : num) {
            while((!st.empty()) && (st.top() > (ch-'0')) && (count < k)) {
                st.pop();
                count++;
            }
            st.push(ch-'0');
        }

        while(count < k && !st.empty()) {
            st.pop();
            count++;
        } 

        string res;
        while(!st.empty()) {
            res.push_back(st.top() + '0');
            st.pop();
        }

        while(res.size() > 0 && res.back() == '0') res.pop_back();

        reverse(res.begin(), res.end());

        if (res == "") return "0";

        return res;
    }
};