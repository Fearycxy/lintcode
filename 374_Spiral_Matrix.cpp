class Solution {
public:
    /**
     * @param matrix: a matrix of m x n elements
     * @return: an integer list
     */
     //最后结束点的判断有点恶心
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        // write your code here
        vector<int> re;
        const int m = matrix.size();
        if (!m) return re;
        const int n = matrix[0].size();
        for (int i = 0; i < n; i++) {
            re.push_back(matrix[0][i]);
        }
         int len = 1,x = 0, y = n - 1,dir = 1,limit =min(n, m)-1 ;
         if(m != limit+1) limit++;
        while (len <= limit) {
            int i = 0, tp;
            while (i < 2) {
                switch (dir) {
                    case 0:
                        tp = y + n - len ;
                        while (y < tp) {
                            y++;
                            re.push_back(matrix[x][y]);
                        }
                        break;
                    case 1:
                        tp = x + m - len ;
                        while (x < tp) {
                            x++;
                            re.push_back(matrix[x][y]);
                        }
                        break;
                    case 2:
                        tp = y - n + len;
                        while (y >tp) {
                            y--;
                            re.push_back(matrix[x][y]);
                        }
                        break;
                    case 3:
                        tp = x - m + len ;
                        while (x >tp) {
                            x--;
                            re.push_back(matrix[x][y]);
                        }
                }
                i++;
                dir = (dir + 1) % 4;
            }
            len++;
        }
        return re;
    }
};
