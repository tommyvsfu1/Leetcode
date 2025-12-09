// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         int j = 0;
//         int i = 0;
//         int cur = 0;
//         int res = INT_MAX;
//         for (int i = 0; i < n; i++) {
//             while (j < n && cur < target) {
//                 cur += nums[j];
//                 j++;
//             }

//             if (cur >= target)
//                 res = min(res, j-i);

//             if (cur >= 0)
//                 cur -= nums[i];
//         }
//         if (res == INT_MAX) return 0;
//         return res;
//     }
// };
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         vector<int> presum(n+1, 0);
//         for (int i = 0; i < n; i++) {
//             presum[i+1] = presum[i] + nums[i];
//         }

//         int res = INT_MAX;

//         for (int j = n; j >= 1; j--) {
//             int i = upper_bound(presum.begin(), presum.end(), presum[j]-target) - presum.begin();
//             if (i != 0 && i-1 <= j-1) {
//                 // [i-1,j-1]
//                 res = min(res, j-1 - (i-1) + 1);
//             }
//         }
//         if (res == INT_MAX) return 0;
//         return res;
//     }
// };
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n+1, 0);
        for (int i = 0; i < n; i++) {
            presum[i+1] = presum[i] + nums[i];
        }

        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            auto pos = lower_bound(presum.begin(), presum.end(), presum[i]+target);

            if (pos != presum.end()) {
                int j = distance(presum.begin(), pos);
                res = min(res, j-i);
            }

        }
        if (res == INT_MAX) return 0;
        return res;
    }
};
// pre[i:j] >= target
// pre[j+1] - pre[i] >= target


// pre[j+1] >= pre[i] + target

// pre[j+1] - target >= pre[i]

// pre[i] <= pre[j+1] - target
// pre[i] > pre[j+1]-target

// pre[j+1] >= target + pre[i];