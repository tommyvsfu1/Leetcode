class Solution {
    priority_queue<int> pq;
public:
    int lastStoneWeight(vector<int>& stones) {
        for (auto element : stones) {
            pq.push(element);
        }

        while (pq.size() > 1) {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            
            if (top1 - top2 > 0) {
                pq.push(top1 - top2);
            }
        }
        
        if (pq.size() == 0) return 0;
        
        return pq.top();
    }
};
