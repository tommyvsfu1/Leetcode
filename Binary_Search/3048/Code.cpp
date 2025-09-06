class Solution {
public:
    bool checkValid(vector<int>& nums, vector<int>& changeIndices, int k) {
        vector<int> last_appear(nums.size(), -1);

        for (int i = 0; i < k; i++) {
            last_appear[changeIndices[i] - 1] = i;
        }

        for (int j = 0; j < last_appear.size(); j++) {
            if (last_appear[j] == -1) return false;
        }

        int count = 0;
        for (int t = 0; t < k; t++) {
            int index = changeIndices[t] - 1;

            if (last_appear[index] != t) {
                count++;
            }
            else {
                count -= nums[index];
                if (count < 0) return false;
            }
        }

        return true;
    }

    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int left = 1;
        int right = changeIndices.size();

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (checkValid(nums, changeIndices, mid) == true) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        if (checkValid(nums, changeIndices, left) == true) return left;
        return -1;
    }
};
