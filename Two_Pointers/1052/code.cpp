class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                sum += customers[i];
        }

        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 1)
                sum += customers[i];
            if (i-minutes >=0 && grumpy[i-minutes] == 1)
                sum -= customers[i-minutes];
            res = max(res, sum);
        }
        return res;
    }
};