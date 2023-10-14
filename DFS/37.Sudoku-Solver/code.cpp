class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<pair<int,int>>& ordering, int index, vector<unordered_set<char>>& row, vector<unordered_set<char>>& col, vector<vector<unordered_set<char>>>& sub) {
        if (index >= ordering.size()) {
            bool solved = true;
            for (int i = 0; i < 9; i++) {
                if (row[i].size() != 9)
                    solved = false;
                if (col[i].size() != 9)
                    solved = false;
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (sub[i][j].size() != 9)
                        solved = false;
                }
            }
            return solved;
        }

        int i = ordering[index].first;
        int j = ordering[index].second;
        for (char c = '1'; c <= '9'; c++) {
            if (row[i].find(c) != row[i].end()) continue;
            if (col[j].find(c) != col[j].end()) continue;
            if (sub[i/3][j/3].find(c) != sub[i/3][j/3].end()) continue;
            row[i].insert(c);
            col[j].insert(c);
            sub[i/3][j/3].insert(c);
            board[i][j] = c;
            if(dfs(board, ordering, index+1, row, col, sub))
                return true;
            board[i][j] = '.';
            row[i].erase(c);
            col[j].erase(c);
            sub[i/3][j/3].erase(c);        
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> col(9);
        vector<vector<unordered_set<char>>> sub(3, vector<unordered_set<char>>(3));

        vector<pair<int,int>> ordering;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    sub[i/3][j/3].insert(board[i][j]);
                }
                else {
                    ordering.push_back({i,j});
                }
            }
        }

        dfs(board, ordering, 0, row, col, sub);
    }
};