class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        for (int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], height[i+1]);

        int res = 0;
        for (int i = 0; i < n; i++) {
            int sum = min(leftMax[i], rightMax[i]) - height[i];

            if (sum >= 0)
                res += sum;
        }
        return res;
    }
};