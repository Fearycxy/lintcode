class Solution {
public:
    /**
     * @param matrix: A lsit of lists of integers
     * @return: nothing
     */
    void setZeroes(vector<vector<int>> &matrix) {
        // write your code here
        int n = matrix.size();
        if(!n) return;
        int m = matrix[0].size();
        bool h = false,s = false;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                    if(!i) h = true;
                    if(!j) s = true;
                }
            }
        }
        for(int i =1;i<m;i++){
            if(matrix[0][i]==0){
                for(int j = 0;j<n;j++){
                    matrix[j][i]=0;
                }
            }
        }
         for(int i =1;i<n;i++){
            if(matrix[i][0]==0){
                for(int j = 0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        if(s)  for(int i = 0;i<n;i++) matrix[i][0]=0;
        if(h)  for(int i = 0;i<m;i++) matrix[0][i]=0;
    }
};
