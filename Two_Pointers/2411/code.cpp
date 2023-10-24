class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(32, 0);
        vector<int> res(n);
        int j = n-1;
        for (int i = n-1; i>=0; i--) {
            for (int k = 0; k < 32; k++)
                count[k] += (nums[i]>>k)&1;
            
            while(i<j && okRemove(nums[j], count)) {
                for (int k = 0; k < 32; k++)
                    count[k] -= (nums[j]>>k)&1;
                j--;
            }

            res[i] = j-i+1;
        }
        return res;
    }
    bool okRemove(int num, vector<int>& count) {
        for (int k = 0; k < 32; k++) {
            if (count[k] == 1 && ((num>>k)&1))
                return false;
        }
        return true;
    }
};