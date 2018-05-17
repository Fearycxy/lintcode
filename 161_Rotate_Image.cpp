class Solution {
public:
    /**
     * @param matrix: a lists of integers
     * @return: nothing
     */
    void rotate(vector<vector<int>> &matrix) {
        // write your code here
        n = matrix.size();n--;
        int m = n>>1;
        int g = n&1==1 ? m: m-1;
        for(int i = 0;i<=g;i++){
            for(int j = 0;j<=m;j++){
                 int x =i,y = j;
                 int last = matrix[i][j];
                for(int k=0;k<3;k++){
                    rotate(x,y);
                    swap(last,matrix[x][y]);
                    
                }
                matrix[i][j] = last;
            }
        }
    }
    
    int n;
    void rotate(int &x,int &y){
        int s = x;
        x = y;
        y = n-s;
    }
};
