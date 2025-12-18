class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long res = 0;

        vector<int> nums = balance;
        int n = nums.size();
        int idx = -1;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += balance[i];
            if (balance[i] < 0) idx = i;
        }

        if (sum < 0) return -1;
        if (idx == -1) return 0;

        long long val = balance[idx];
        int left = (idx-1+n) % n;
        int right = (idx+1) % n;
        int dist = 1;
        while (val < 0) {
            if (balance[left] > 0) {
                long long take = min((long)balance[left], (long)abs(val));
                val += take;
                res += take * dist;
                balance[left] -= take;
            }

            if (balance[idx] < 0 && balance[right] > 0) {
                long long take = min((long)balance[right], (long)abs(val));
                val += take;
                res += take * dist; 
                balance[right] -= take;
            }

            left = (left-1+n) % n;
            right = (right+1) % n;
            dist++;            
        }
        return res;
    }
};