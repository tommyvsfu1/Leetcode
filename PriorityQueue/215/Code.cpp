class Solution {
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (auto element : nums) {
            if (pq.size() < k) {
                pq.push(element);
            }
            else {
                if (element > pq.top()) {
                    pq.pop();
                    pq.push(element);
                }
            }
        }
        return pq.top();
    }
};
