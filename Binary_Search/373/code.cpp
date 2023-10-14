class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        

        long left = INT_MIN;
        long right = INT_MAX;

        while (left < right) {
            long mid = left + (right - left) / 2;

            long count = countLessOrEqual(nums1, nums2, mid);

            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }

        int m = left;
  
        vector<vector<int>> res;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size() && nums1[i] + nums2[j] < m; j++) {
                res.push_back({nums1[i], nums2[j]});
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size() && nums1[i] + nums2[j] <= m && res.size() < k; j++) {
                if (nums1[i] + nums2[j] == m)
                    res.push_back({nums1[i], nums2[j]});
            }
        }
        
        return res;
    }
    long countLessOrEqual(vector<int>& nums1, vector<int>& nums2, int mid) {

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
