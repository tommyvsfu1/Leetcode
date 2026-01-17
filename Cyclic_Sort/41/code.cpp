class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 0);

        for (int i = 1; i <= n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]] != nums[i]) {
                int index = nums[i];
                swap(nums[index], nums[i]);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (nums[i] != i) return i;
        }
        return n+1;
    }
};