class Solution {
    static bool cmp(vector<int>&a, vector<int>&b) {
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), cmp);

        int i = 0;
        int res = 0;
        while (i < n) {
            res++;
            int j = i + 1;
            while(j < n && intervals[i][1] > intervals[j][0])
                j++;
            i = j;
        }
        return n - res;
    }
};