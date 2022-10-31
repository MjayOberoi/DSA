class Solution {
public:
    bool check(vector<vector<char>> &board, int i, int j, char val){
        int row = (i/3)*3, column = (j/3)*3;
        
        for(int x=0; x<9; x++) 
            if(board[x][j] == val || board[i][x] == val) return false;
        
        for(int x=row; x<row+3; x++)
            for(int y=column; y<column+3; y++)
                if(board[x][y] == val) return false;
        
        return true;
    }
    
    bool solve(vector<vector<char>> &board, int i, int j){
        if(i==9) return true;
        if(j==9) return solve(board, i+1, 0);
        if(board[i][j] != '.') return solve(board, i, j+1);

        for(char c='1'; c<='9'; c++){
            if(check(board, i, j, c)){
                board[i][j] = c;
                if(solve(board, i, j+1)) return true;   
            }
        }
        board[i][j] = '.';
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        return;
    }
};