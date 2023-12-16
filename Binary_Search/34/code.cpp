class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        vector<int> res(2, -1);

        while(low < high) {
            int mid = low + (high-low)/2;

            if (nums[mid] == target) {
                high = mid;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        
        if (low == high && nums[low] == target) res[0] = low;

        low = 0;
        high = n-1;
        while(low < high) {
            int mid = low + (high-low+1)/2;

            if (nums[mid] == target) {
                low = mid;
            }
            else if (nums[mid] < target) {
                low = mid;
            }
            else {
                high = mid-1;
            }
        }

        if (low == high && nums[low] == target) res[1] = low;

        return res;
    }
};