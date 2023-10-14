using LL = long long;
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {

        LL left = -1e10;
        LL right = 1e10;

        while (left < right) {

            LL mid = left + (right - left) / 2;

            LL count = countLessOrEqual(mid, nums1, nums2);

            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }

    long long countLessOrEqual(LL mid, vector<int>& nums1, vector<int>& nums2) {
        LL res = 0;

        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] > 0) {
                LL y = floor(mid*1.0/nums1[i]);

                auto pos = upper_bound(nums2.begin(), nums2.end(), y);
                int j = pos - nums2.begin();
                // [0,j-1]
                res += (j);
            }
            else if (nums1[i] == 0) {
                if (mid < 0) res += 0;
                else res += nums2.size();
            }
            else {
                LL y = ceil(mid*1.0/nums1[i]);
                auto pos = lower_bound(nums2.begin(), nums2.end(), y);
                int j = pos - nums2.begin();
                // j, n-1
                res += (nums2.size() - j);
            }
        }
        return res;
    }
};