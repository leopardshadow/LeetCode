class Solution {
public:
    
    vector<vector<bool>> visited;
    
    int direc[5] = {0, 1, 0, -1, 0};
    bool exist(vector<vector<char>>& board, string word) {
        
        int rSize = board.size(),
            cSize = board[0].size();
        
        vector<bool> emptyRow(cSize, false);
        for(int r = 0; r < rSize; r++)
            visited.push_back(emptyRow);
        
        for(int r = 0; r < rSize; r++) {
            for(int c = 0; c < cSize; c++) {
                visited[r][c] = true;
                if(search(board, word, r, c))
                    return true;
                visited[r][c] = false;
            }
        }
        return false;
    }
    
    bool search(vector<vector<char>>& board, string word, int r, int c) {
        
        if(word == "") return true;
        if(word.length() == 1) return word[0] == board[r][c]; 
        //  ^^^ [["a"]] "a" ^^^ corner case
        if(board[r][c] != word[0]) return false;
        
        int rSize = board.size(),
            cSize = board[0].size();
        int nr, nc;    
        
        for(int d = 0; d < 4; d++) {
            nr = r + direc[d];
            nc = c + direc[d+1];
            if(nr >= 0 && nr < rSize && nc >= 0 && nc < cSize && !visited[nr][nc]) {
                visited[nr][nc] = true;
                if(search(board, word.substr(1), nr, nc))
                    return true;
                visited[nr][nc] = false;
            }
        }
        return false;
    }

};