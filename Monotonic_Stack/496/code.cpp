class Solution {
private:
    unordered_map<int, int> nextGreater;
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> st;
        
        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                nextGreater[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            if (nextGreater.find(nums1[i]) == nextGreater.end()) {
                res.push_back(-1);
            }
            else {
                res.push_back(nextGreater[nums1[i]]);
            }
        }
        return res;
    }
};