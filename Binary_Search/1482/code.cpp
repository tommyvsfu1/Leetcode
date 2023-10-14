class Solution {
public:
    int numBou(vector<int>& bloomDay, int mid, int k) {
        int res = 0;

        int curr = 0;
        for (auto day : bloomDay) {
            if (day <= mid) curr++;
            else curr = 0;

            if (curr == k) {
                res++;
                curr = 0;
            }
        }

        return res;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left = 1;
        int right = INT_MAX;

        while (left < right) {
            int mid = left + (right - left) / 2;

            int count = numBou(bloomDay, mid, k);

            if (count >= m)
                right = mid;
            else
                left = mid + 1;

        }

        if (numBou(bloomDay, right, k) >= m) return right;
        return -1;
    }
};