class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        stack<int> st1;
        stack<int> st2;
        vector<int> res(n, -1);

        for (int i = 0; i < n; i++) {
            while(!st2.empty() && nums[st2.top()] < nums[i]) {
                res[st2.top()] = nums[i];
                st2.pop();
            }

            vector<int> temp;
            while (!st1.empty() && nums[st1.top()] < nums[i]) {
                temp.push_back(st1.top());
                st1.pop();
            }

            for (int i = temp.size() - 1; i >= 0; i--)
                st2.push(temp[i]);
            
            st1.push(i);
        }

        return res;

    }
};