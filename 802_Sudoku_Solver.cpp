//九章的解法
class Solution {
public:
     typedef vector<bool> vb;
     vector<vb> row;
     vector<vb> col;
     vector<vector<vb>> cell;
    /**
     * @param board: the sudoku puzzle
     * @return: nothing
     */
    void solveSudoku(vector<vector<int>> &board) {
        // write your code here
        row = vector<vb>(9,vb(10,false));
        col = vector<vb>(9,vb(10,false));
        cell = vector<vector<vb>>(3,vector<vb>(3,vb(10,false)));
        for(int i=0;i<9;i++)
            for(int j =0;j<9;j++){
                if(int k = board[i][j]){
                    row[i][k]=col[j][k]= true;
                    cell[i/3][j/3][k] = true;
                }
            }
        dfs(board,0,0);
    }
    
    bool dfs(vector<vector<int>> &board,int i,int j){
        if(i == 9) return true;
        if(j == 9) return dfs(board,i+1,0);
        if(board[i][j]) return dfs(board, i, j + 1);
        for(int k=1;k<=9;k++){
            if(!row[i][k] && !col[j][k] && !cell[i/3][j/3][k]){
                board[i][j] = k;
                row[i][k] = col[j][k] = cell[i/3][j/3][k] = true;
                if(dfs(board,i,j+1))return true;
                board[i][j] = 0;
                row[i][k] = col[j][k] = cell[i/3][j/3][k] = false;
            }
        }
        return false;
    }
};
