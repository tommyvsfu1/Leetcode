class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        // sorting potions as strictly increasing array
        sort(potions.begin(), potions.end());

        // results array
        vector<int> res;
        for (int i = 0; i < n; i++) {
            long long target = ceil(double(success) / spells[i]);
            auto it = lower_bound(potions.begin(), potions.end(), target);
            if (it != potions.end()) {
                int j = distance(potions.begin(), it);
                res.push_back(m-j);
            }
            else {
                res.push_back(0);
            }
        }
        return res; 
    }
};