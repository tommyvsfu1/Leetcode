class Solution {
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] != b[0])
            return a[0] < b[0];
        else {
            return a[1] > b[1];
        }
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int n = intervals.size();
        int i = 0;
        int res = 0;
        while (i < n) {
            res++;
            int j = i + 1;
            while (j < n && intervals[j][0] >= intervals[i][0] && intervals[j][1] <= intervals[i][1]) {
                j++;
            }
            i = j;
        }
        return res;
    }
};

// 1 2 3 4
// [ ]
// [     ]
//     [ ]

// // [  ]
// //  [      ]
// // [            ]
  

