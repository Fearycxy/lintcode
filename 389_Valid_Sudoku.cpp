class Solution {
public:
    /**
     * @param board: the board
     * @return: whether the Sudoku is valid
     */
    bool isValidSudoku(vector<vector<char>> &board) {
        // write your code here
        bool de[9] = {0};
        for(int i = 0;i<9;i++){
            fill(de,de+9,false);
            for(int j = 0;j<9;j++)
                if(!isvalid(de,board[i][j])) return false;
            fill(de,de+9,false);
            for(int j = 0;j<9;j++)
                if(!isvalid(de,board[j][i])) return false;
        }
        for(int i = 0;i<9;i=i+3)
            for(int j = 0;j<9;j=j+3){
                 fill(de,de+9,false);
                for(int a =i;a<i+3;a++)
                    for(int b = j;b<j+3;b++)
                         if(!isvalid(de,board[a][b])) return false;
            }
        return true;    
        
        
    }
    
    inline bool isvalid(bool de[9],char c){
        if(c == '.') return true;
        if(de[c-'1']) return false;
        return de[c-'1'] = true;
    }
};
