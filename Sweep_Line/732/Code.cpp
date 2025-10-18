class MyCalendarThree {
public:
    map<int,int> Map;
    MyCalendarThree() {
        
    }
    int book(int startTime, int endTime) {
        Map[startTime] += 1;
        Map[endTime] -= 1;

        int res = 0;
        int count = 0;
        for (auto& [t, diff] : Map) {
            count += diff;
            res = max(res, count);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */
