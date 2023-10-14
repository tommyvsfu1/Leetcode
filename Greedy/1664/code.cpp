class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftodd(n, 0);
        vector<int> lefteven(n, 0);
        int oddsum = 0, evensum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evensum += nums[i];
            }
            else {
                oddsum += nums[i];
            }
            lefteven[i] = evensum;
            leftodd[i] = oddsum;
        }

        oddsum = 0;
        evensum = 0;
        vector<int> rightodd(n, 0);
        vector<int> righteven(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (i % 2 == 0) 
                evensum += nums[i];
            else
                oddsum += nums[i];
            righteven[i] = evensum;
            rightodd[i] = oddsum;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int left_even = 0, left_odd = 0, right_even = 0, right_odd = 0;
            if (i > 0) {
                left_even = lefteven[i-1];
                left_odd = leftodd[i-1];
            }
            if (i < n - 1) {
                right_even = righteven[i+1];
                right_odd = rightodd[i+1];
            }
            if (left_even + right_odd == left_odd + right_even)
                res++;
        }
        return res;
    }
};