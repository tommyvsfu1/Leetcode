class Solution {
public:
    string reorganizeString(string s) {
        
        int n = 2;
        unordered_map<char,int> count;

        for (auto ch : s) {
            count[ch]++;
        }

        priority_queue<pair<int,char>> pq;
        for (auto element : count) {
            pq.push({element.second, element.first});
        }

        string res = "";
        while(!pq.empty()) {
            int k = min((int)pq.size(), n);
            vector<pair<int,char>> temp;
            for (int i = 0; i < k; i++) {
                pair<int,char> f = pq.top();
                pq.pop();
                f.first = f.first - 1;

                if (res.size() > 0) {
                    if (f.second != res.back())
                        res.push_back(f.second);
                    else {
                        return "";
                    }
                }
                else {
                    res.push_back(f.second);
                }                
                
                if (f.first > 0) {
                    temp.push_back(f);
                }
            }

            for (auto element : temp) {
                pq.push(element);
            }
        }
        return res;
    }
};
