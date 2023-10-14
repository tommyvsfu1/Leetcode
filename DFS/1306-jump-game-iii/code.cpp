class Solution {
private:
    bool visited[50000];
public:
    bool dfs(vector<int>& arr, int index) {
        if (index < 0 || index >= arr.size())
            return false;
        
        if (visited[index])
            return false;

        visited[index] = true;                

        if (arr[index] == 0) {
            return true;
        }

        bool res = false;
        res = dfs(arr, index - arr[index]) | dfs(arr, index + arr[index]);
        return res;

    }
    bool canReach(vector<int>& arr, int start) {
        for (int i = 0; i < arr.size(); i++) {
            visited[i] = false;
        }
        return dfs(arr, start);

    }
};