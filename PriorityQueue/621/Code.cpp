class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n++;
        int res = 0;
        unordered_map<char,int> count;
        for (auto ch : tasks) {
            count[ch]++;
        }

        priority_queue<int> pq;
        for (auto element : count) {
            pq.push(element.second);
        }

        while(!pq.empty()) {
            int k = min((int)pq.size(), n);
            vector<int> temp;

            for (int i = 0; i < k; i++) {
                int f = pq.top();
                pq.pop();
                f--;
                if (f > 0) temp.push_back(f);
            }
            
            if (temp.size() > 0)
                res += n;
            else
                res += k;
            
            for (auto c : temp) {
                pq.push(c);
            }
        }
        return res;
    }
};
