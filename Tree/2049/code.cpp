using LL = long long;
class Solution {
    int n = 0;
    vector<vector<int>> children;
    unordered_map<LL, int> mp;
public:
    int countHighestScoreNodes(vector<int>& parents) {
        n = parents.size();
        children.resize(n);
        for (int i = 1; i < n; i++) 
            children[parents[i]].push_back(i);
        
        dfs(0);

        int res = 0;
        LL res_key = -1;
        for (auto element : mp) {
            LL key = element.first;
            int value = element.second;
            if (key > res_key) {
                res = value;
                res_key = key;
            }
        }
        return res;
    }
    int dfs(int node) {
        vector<int> sub;
        int sub_total = 0;
        for (int child : children[node]) {
            int num = dfs(child);
            sub.push_back(num);
            sub_total += num;
        }

        LL score = 1;
        int upper = n - 1 - sub_total;
        if (upper > 0) score *= upper;
        for (int num_node : sub) {
            if (num_node > 0) score *= num_node;
        }
        mp[score] += 1;

        return sub_total + 1;
    }
};