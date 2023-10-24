class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int k = n-1; k >= 0; k--) {
            int i = 0;
            int j = k-1;
            while(i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    res += (j-i);
                    j--;
                }
                else {
                    i++;
                }   
            }
        }
        return res;
    }
};