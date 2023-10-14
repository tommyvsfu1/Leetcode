class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        double left = 0;
        double right = 1;
        double mid = 0;
        while (left < right) {
            mid = (right+left) / 2.0;


            int count = 0;
            for (int i = 0; i < arr.size(); i++) {

                // nums[i] / nums[j] <= mid
                // nums[j] >= nums[i] / mid
                // 尋找所有的nums[j] 
                auto pos = lower_bound(arr.begin(), arr.end(), arr[i]*1.0/mid);
                count += arr.end() - pos;

            }

            if (count < k)
                left = mid;
            else if (count > k)
                right = mid;
            else
                break;
        }
        
        double ans = -1;
        vector<int> res;
        // 因為是浮點數，while loop出來的left(right)不是答案，所以我們再用left來找出最大的prime fraction
        for (int i = 0; i < arr.size(); i++) {
            auto pos = lower_bound(arr.begin(), arr.end(), arr[i]*1.0/mid);

            if (pos != arr.end() && arr[i]*1.0/arr[pos-arr.begin()] > ans) {
                ans = arr[i]*1.0 / arr[pos-arr.begin()];
                res = {arr[i], arr[pos-arr.begin()]};
            }
        }
        return res;

    }
};
