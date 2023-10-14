class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = 1 + wordList.size();

        vector<vector<int>> graph(n, vector<int>());
        unordered_set<string> Set;
        unordered_map<string, int> mp;
        for (int i = 0; i < wordList.size(); i++) {
            Set.insert(wordList[i]);
            mp[wordList[i]] = i + 1;
        }

        wordList.insert(wordList.begin(), beginWord);

        for (int i = 0; i < wordList.size(); i++) {
            string s = wordList[i];
            for (int j = 0; j < s.size(); j++) {
                string t = s;
                for (char c = 'a'; c <= 'z'; c++) {
                    t[j] = c;
                    if (Set.find(t) != Set.end()) {
                        graph[i].push_back(mp[t]);
                    } 
                }
            }
        }
        
        queue<int> q;
        vector<int> visited(n, 0);
        q.push(0);
        int time = 0;
        while(!q.empty()) {
            int len = q.size();
            while (len--) {
                int index = q.front();
                visited[index] = 1;

                if (wordList[index] == endWord)
                    return time + 1;
                
                q.pop();
                for (auto node : graph[index]) {
                    if (visited[node] == 0) {
                        q.push(node);
                    }
                }
            }
            time++;
        }

        return 0;
    }
};