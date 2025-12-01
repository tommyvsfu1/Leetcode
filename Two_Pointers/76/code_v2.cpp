class Solution {
public:
    unordered_map<char,int> Map;
    unordered_map<char,int> TargetMap;
    bool IsWindow(string &s, int j) {
        Map[s[j]]++;
        bool res = true;
        for (auto element : TargetMap) {
            if (Map.find(element.first) == Map.end()) res = false;
            if (Map[element.first] < element.second) res = false;
        }
        Map[s[j]]--;
        return res;
    }
    string minWindow(string s, string t) {
        for (int i = 0; i < t.size(); i++) {
            TargetMap[t[i]]++;
        }
         
        int j = 0;
        int res = INT_MAX;
        vector<int> res_pos(2, 0);
        for (int i = 0; i < s.size(); i++) {

            while (j < s.size() && IsWindow(s, j) == false) {
                Map[s[j]]++;
                j++;
            }
            //cout << i << " " << j << endl;
            
            if (j < s.size() && IsWindow(s, j)) {
                int sub_len = j - i + 1;
                if (sub_len < res) {
                    res = sub_len;
                    res_pos[0] = i;
                    res_pos[1] = j;
                }
            }
            Map[s[i]]--;
        }
        if (res == INT_MAX) return "";
        return s.substr(res_pos[0], res_pos[1]-res_pos[0]+1);
    }
};