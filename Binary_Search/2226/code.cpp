class Solution {
public:
    long long count(vector<int>& candies, long long mid) {
        long long res = 0;

        for (auto &c : candies) {
            res += (c / mid);
        }

        return res;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1;
        long long right = 0;
        for (auto c : candies)
            right += c;
        
        while (left < right) {
            long long mid = left + (right - left + 1) / 2; // +1是因為下面是寫成 left = mid 跟 right = mid - 1，這是一個小技巧
            long long total = count(candies, mid);

            if (total >= k) {
                left = mid;
            }
            else
                right = mid - 1;
        }

        if (count(candies, left) >= k)
            return left;
        return 0;
    }
};