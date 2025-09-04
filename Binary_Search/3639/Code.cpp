class Solution {
public:
    inline long long ListAll(long long k) {
        if (k == 0) return 0;
        return ((k-1) * k / 2) + k;
    }
    long long countValid(string s, vector<int>& order, int t) {
        long long count = ListAll(s.size());

        int order_size = order.size() - 1;
        int T = min(t, order_size);
        for (int i = 0; i <= T; i++) {
            s[order[i]] = '*';
        }

        int j;
        for (int i = 0; i < s.size();) {
            j = i;
            while (j < s.size() && s[j] != '*') {
                j++;
            }

            count -= ListAll(j-i);
            
            if (i == j) 
                i++;
            else
                i = j;
        }
        return count;
    }
    int minTime(string s, vector<int>& order, int k) {
        int left = 0;
        int right = INT_MAX;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (countValid(s, order, mid) < k) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        if (countValid(s, order, left) < long(k)) return -1;
        return left;
    }
};
