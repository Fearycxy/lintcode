class Solution {
public:
    /**
     * @param n: An integer
     * @return: a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // write your code here
        vector<vector<int>> re (n,vector<int>(n,0));
        for (int i = 0; i < n; i++) {
            re[0][i] = i+1;
        }
         int len = 1,x = 0, y = n - 1,dir = 1,limit =n-1 ;
         int p = n+1;
        while (len <= limit) {
            int i = 0, tp;
            while (i < 2) {
                switch (dir) {
                    case 0:
                        tp = y + n - len ;
                        while (y < tp) {
                            y++;
                            re[x][y] = p++;
                        }
                        break;
                    case 1:
                        tp = x + n - len ;
                        while (x < tp) {
                            x++;
                            re[x][y] = p++;
                        }
                        break;
                    case 2:
                        tp = y - n + len;
                        while (y >tp) {
                            y--;
                            re[x][y] = p++;
                        }
                        break;
                    case 3:
                        tp = x - n + len ;
                        while (x >tp) {
                            x--;
                            re[x][y] = p++;
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


//九章的划分更好，或者说我的划分实在是自找麻烦

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n,0));
        int cnt = n/2;
        int val = 1;
        for (int i = 0; i < cnt; i++) {
            int last = n - 1 - i;
            for (int j = i; j < last; j++) 
                ret[i][j] = val++;
            for (int j = i; j < last; j++)
                ret[j][last] = val++;
            for (int j = last; j > i; j--)
                ret[last][j] = val ++;
            for (int j = last; j > i; j--)
                ret[j][i] = val++;
        }
        if (n % 2 == 1) {
            ret[n/2][n/2] = val;
        }
        return ret;
    }
};
