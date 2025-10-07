class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<pair<long,int>>> pq;

        for (int i = 0; i < points.size(); i++) {
            long x = points[i][0];
            long y = points[i][1];
            long d = x * x + y * y;
            pq.push({d, i});
        }

        vector<vector<int>> res;
        for (int i = 0; i < k; i++) {
            auto [d, index] = pq.top();
            pq.pop();
            res.push_back({points[index][0], points[index][1]}); 
        }
        return res;
    }
};
