class Solution {
public:
    int CountGreaterOrEqual(vector<int>& nums, int mid) {
        int count = 0;
        for (auto a : nums) {
            if (a >= mid)
                count++;
        }
        return count;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        int left = -1e4;
        int right = 1e4;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            int count = CountGreaterOrEqual(nums, mid);

            if (count >= k) {
                left = mid;
            }
            else {
                right = mid - 1;
            }

        }
        return left;

    }
};