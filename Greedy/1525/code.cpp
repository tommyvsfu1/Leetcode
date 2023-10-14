class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> presum(n);
        vector<int> sufsum(n);

        unordered_set<int> state;
        for (int i = 0; i < n; i++) {
            state.insert(s[i]-'a');
            presum[i] = state.size();
        }

        state.clear();
        for (int i = n - 1; i >= 0; i--) {
            state.insert(s[i]-'a');
            sufsum[i] = state.size();
        }
        
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            if (presum[i] == sufsum[i+1])
                res++;
        }
        return res;

    }
};