/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
    static bool cmp(pair<int,int>& a, pair<int,int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        else {
            return a.first < b.first;
        }
    }
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<pair<int,int>> q;
        for (int i = 0; i < schedule.size(); i++) {
            for (int j = 0; j < schedule[i].size(); j++) {
                q.push_back({schedule[i][j].start, 1});
                q.push_back({schedule[i][j].end, -1});
            }
        }

        sort(q.begin(), q.end(), cmp);


        vector<pair<int,int>> sorted_sched;
        int start = -1;
        int end = -1;
        int count = 0;
        for (int i = 0; i < q.size(); i++) {
            if (start == -1) {
                start = q[i].first;
            }
            count += q[i].second;

            if (count == 0) {
                end = q[i].first;
                sorted_sched.push_back({start,end});
                start = -1;
                end = -1;
            }
        }
        vector<Interval> res;
        for (int i = 0; i < sorted_sched.size() - 1; i++) {
            int curr_end = sorted_sched[i].second;
            int next_start = sorted_sched[i+1].first;
            Interval inr = Interval(curr_end, next_start);
            res.push_back(inr);
        }
        return res;
    }
};
