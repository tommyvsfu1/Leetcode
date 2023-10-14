class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        int res = 0;
        long sum1 = 0;
        long sum2 = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum1 += (long)arr[i];
            sum2 += (long)sorted_arr[i];

            if (sum1 == sum2) {
                res += 1;
                sum1 = 0;
                sum2 = 0;
            }
        }
        return res;
    }
};
