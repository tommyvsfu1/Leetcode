class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        long long sum1 = 0, sum2 = 0;
        long long M = 1e9 + 7;

        int i = 0, j = 0;
        while(i < m || j < n) {
            if (i >= m) {
                sum2 += nums2[j];
                j++;
            }
            else if (j >= n) {
                sum1 += nums1[i];
                i++;
            }
            else {
                if (nums1[i] < nums2[j]) {
                    sum1 += nums1[i];
                    i++;
                }
                else if (nums2[j] < nums1[i]) {
                    sum2 += nums2[j];
                    j++;
                }
                else {
                    long long maxSum_until_now = max(nums1[i]+sum1, nums2[j]+sum2);
                    sum1 = maxSum_until_now;
                    sum2 = maxSum_until_now;
                    i++;
                    j++;
                }
            }
        }

        return max(sum1, sum2) % M;
    }
};