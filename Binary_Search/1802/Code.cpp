class Solution {
public:
    bool isValid(int n, int index, int maxSum, int mid) {
        long long sum = 0;
        long long k = mid;

        int span_index_to_1 = k - 1;
        long long left_span = min(index, span_index_to_1);
        long long left_bound = index - left_span;
        long long right_span = min(n - 1 - index, span_index_to_1);
        long long right_bound = index + right_span;

        long long left_bound_sum = k * left_span -  (left_span * (left_span + 1)) / 2;
        long long right_bound_sum = k * right_span - (right_span * (right_span + 1)) / 2;
        
        left_bound_sum += long(left_bound);
        right_bound_sum += long(n - 1 - right_bound);
        sum += (left_bound_sum + right_bound_sum);
        sum += mid;
        //cout << " sum " << sum << " maxSum " << maxSum << " k " << k << " index " << index << " right bound " << right_bound << " left bound " << left_bound << " right span " << right_span << " left span " << left_span << " right bound sum " << right_bound_sum << " left bound sum " << left_bound_sum << endl;
        return (sum <= long(maxSum));
    }
    int maxValue(int n, int index, int maxSum) {
        int left = 1;
        int right = 1e9;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;

            if (isValid(n, index, maxSum, mid) == true) {
                left = mid;
            }
            else {
                right = mid - 1;
            }
        } 

        return left;
    }
};







