class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n, 0);
        for (int i = 0; i < n; i++) {
            presum[i] = ( (i==0) ? 0 : presum[i-1]) + nums[i];
        }

        vector<int> leftMax(n, 0);
        vector<int> leftIdx(n, 0);
        int maxSum = 0;
        int maxIdx = 0;
        for (int i = k-1; i < n; i++) {
            // [i-k+1,i]
            int sum = presum[i] - ( (i-k >= 0) ? presum[i-k]: 0);
            if (sum > maxSum) {
                maxSum = sum;
                maxIdx = i-k+1;
            }
            leftMax[i] = maxSum;
            leftIdx[i] = maxIdx;
        }

        vector<int> rightMax(n,0);
        vector<int> rightIdx(n,0);
        maxSum = 0;
        maxIdx = 0;
        for (int i = n - k; i >= 0; i--) {
            // [i, i+k-1]
            int sum = presum[i+k-1] - ( (i-1 >= 0) ? presum[i-1]:0);
            if (sum >= maxSum) {
                maxSum = sum;
                maxIdx = i;
            }
            rightMax[i] = maxSum;
            rightIdx[i] = maxIdx;
        }

        vector<int> res;
        maxSum = 0;
        for (int i = k; (i+2*k-1 <= n-1); i++) {
            int sum = presum[i+k-1] - presum[i-1];
            if (leftMax[i-1] + sum + rightMax[i+k] > maxSum) {
                maxSum = leftMax[i-1] + sum + rightMax[i+k];
                res = {leftIdx[i-1], i, rightIdx[i+k]};
            }
        }
        return res;

    }
};



// [X X X X] X X X X X [X X X X]
//       i-1 i          i+k 
      