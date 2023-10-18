class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;

        int j = 0;
        int flip = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && (nums[j] == 1 || flip < k)) {
                if (nums[j] == 0)
                    flip++;
                j++;
            }
            res = max(res, j-i);
            if (nums[i] == 0)
                flip--;
        }   
        return res;
    }
};