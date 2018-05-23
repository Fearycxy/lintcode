class Solution {
public:
    /**
     * @param matrix: An array of integers
     * @return: An array of integers
     */
    vector<int> printZMatrix(vector<vector<int>> &matrix) {
        // write your code here
        bool down = false;
        vector<int >re;
        int m = matrix.size();
        if(!m) return re;
        int n = matrix[0].size();
        int i = 0,j=0;
        while(true){
            re.push_back(matrix[i][j]);
            if(i==m-1&&j==n-1) return re;
            if(down){
                if(i==m-1||j==0){
                    if(i<m-1)i++;
                    else j++;
                   down = false;
                }else{
                    if(i<m-1)i++;
                    if(j) j--;
                }
            }else{
                if(i==0||j==n-1){
                    if(j<n-1)j++;
                    else i++;
                    down = true;
                }else{
                    if(i)i--;
                    if(j<n-1)j++;
                }
            }
        }
    }
};
