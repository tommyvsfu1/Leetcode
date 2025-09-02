class Solution {
public:
    inline int countMissing(vector<int>& arr, int index) {
        int num_in_arr = index + 1;
        return arr[index] - num_in_arr;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (countMissing(arr, mid) < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        int missing = countMissing(arr, right);
        if (missing == 0) {
            return arr[right] + k;
        }
        else if (missing >= k) {
            return arr[right] - 1 - (missing - k);
        }
        else {
            return arr[right] + (k - missing);
        }
    }
};
