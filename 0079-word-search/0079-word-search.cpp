class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Create a visited array initialized with false
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0] && dfs(board, i, j, visited, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visited, string& word, int index) {
        if(index == word.size()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) return false;
        
        visited[i][j] = true;
        
        bool found = dfs(board, i+1, j, visited, word, index+1) ||
                     dfs(board, i-1, j, visited, word, index+1) ||
                     dfs(board, i, j+1, visited, word, index+1) ||
                     dfs(board, i, j-1, visited, word, index+1);
        
        visited[i][j] = false;
        
        return found;
    }
};
