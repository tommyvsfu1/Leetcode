class Solution {
public:
    vector<int> visited;
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        visited.resize(n, 0);
        int cur = start;
        return dfs(arr, cur);
    }
    bool dfs(vector<int>& arr, int index) {
        int n = arr.size();
        if (index >= n || index < 0) return false;


        int right = index + arr[index];
        int left = index - arr[index];
        
        
        visited[index] = 1;

        if (arr[index] == 0) return true;

        bool res = false;
        if (right < n) {
            if (visited[right] == 0) {
                res |= dfs(arr, right);
            }
        }
        if (left >= 0) {
            if (visited[left] == 0) {
                res |= dfs(arr, left);
            }
        }
        return res;
    }
};