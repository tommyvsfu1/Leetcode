class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long left = INT_MIN;
        long right = INT_MAX;

        while (left < right) {
            long mid = left + (right - left) / 2;
            if (count(nums1, nums2, mid) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        vector<vector<int>> res;
        int m = left;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size() && nums1[i] + nums2[j] < m; j++) {
                res.push_back({nums1[i], nums2[j]});
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size() && nums1[i] + nums2[j] <= m && res.size() < k ; j++) {
                if (nums1[i] + nums2[j] == m)
                    res.push_back({nums1[i], nums2[j]});
            }
        }
        return res;
    }
    long count(vector<int>& nums1, vector<int>& nums2, int mid) {
        // u_i + v_i <= mid
        // v_i <= mid - u_i
        // sol: [0, j-1]
        // int res = 0;
        // int j = 0;
        // for (int i = 0; i < nums1.size(); i++) {
        //     //auto iter = upper_bound(nums2.begin(), nums2.end(), mid - nums1[i]);
        //     //res += (iter - nums2.begin());
        // }
        // return res;
        long res = 0;
        int j = nums2.size() - 1;

        for (int i = 0; i < nums1.size(); i++) {

            while (j >= 0 && nums2[j] + nums1[i] > mid) {
                j--;
            }
            res += (j+1);
        }
        return res;
    }
};
