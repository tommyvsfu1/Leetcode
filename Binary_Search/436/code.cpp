class Solution {
public:
    int binarySearch(vector<vector<int>>& intervals, int target) {
        int n = intervals.size();
        long left = 0;
        long right = n - 1;

        while (left < right) {
            long mid = left + (right - left) / 2;

            int start = intervals[mid][0];
            int end = intervals[mid][1];

            if (start >= target) {
                right = mid;
            }
            else { // start < target
                left = mid + 1;
            }
        }

        if (intervals[left][0] < target) return -1;
        return intervals[left][2];
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> I;
        for (int i = 0; i < n; i++) {
            vector<int> cur;
            cur.push_back(intervals[i][0]);
            cur.push_back(intervals[i][1]);
            cur.push_back(i);
            I.push_back(cur);
        }
        
        sort(I.begin(), I.end());

        
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            int end = I[i][1];
            res[I[i][2]] = binarySearch(I, end);
        }
        return res;
    }
};