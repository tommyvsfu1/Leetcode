class Solution {
public:
    double totalHour(vector<int>& dist, int speed) {
        double total = 0;
        for (auto &d : dist) {
            total = ceil(total);
            total += d*1.0/speed;
        }
        return total;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = INT_MAX;
        
        if (hour <= dist.size() - 1) return -1;
        
        double count = 0;

        while (left < right) {
            int mid = left + (right - left) / 2;

            count = totalHour(dist, mid);

            if (count <= hour)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};