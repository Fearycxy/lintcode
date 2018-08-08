class Solution {
public:
    /**
     * @param n: an integer
     * @return: return the matrix
     */
    vector<vector<int>> magicSquare(int n) {
        // Write your code here
        if (n <= 0 || n == 2) return {{}};
        vector<vector<int>> rst(n, vector<int>(n, 0));
        if (n % 2 == 1) odd(rst, n);
        else if (n % 4 == 0) doublyEven(rst, n);
        else singlyEven(rst, n);
        for (auto s:rst) {
            int h = 0;
            for (int y:s) {
                cout << y << "+";

                h += y;
            }
            cout << " = " << h << endl;
        }
        return rst;
    }

private:

    void singlyEven(vector<vector<int>> a, int n) {
        int m = n / 4;
        odd(a, 2 * m + 1);
        int quartSize = (2 * m + 1) * (2 * m + 1);

        int k = quartSize;
        //right bottom
        for (int i = n / 2; i < n; i++) {
            for (int j = n / 2; j < n; j++) {
                a[i][j] = a[i - n / 2][j - n / 2] + k;
            }
        }

        k += quartSize;
        //right upper
        for (int i = 0; i < n / 2; i++) {
            for (int j = n / 2; j < n; j++) {
                a[i][j] = a[i][j - n / 2] + k;
            }
        }

        k += quartSize;
        //left bottom
        for (int i = n / 2; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                a[i][j] = a[i - n / 2][j] + k;
            }
        }

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m; j++) {
                int tmp = a[i][j];
                a[i][j] = a[i + n / 2][j];
                a[i + n / 2][j] = tmp;
            }
        }

        for (int i = 0; i < n / 2; i++) {
            for (int j = n - 1; j > n - m; j--) {
                int tmp = a[i][j];
                a[i][j] = a[i + n / 2][j];
                a[i + n / 2][j] = tmp;
            }
        }

        {
            int tmp = a[n / 4][n / 4];
            a[n / 4][n / 4] = a[n / 4 + n / 2][n / 4];
            a[n / 4 + n / 2][n / 4] = tmp;

            tmp = a[n / 4][0];
            a[n / 4][0] = a[n / 4 + n / 2][0];
            a[n / 4 + n / 2][0] = tmp;

        }

    }

    /*
    1. 顺序填数
    2. 将左上区域i+j为偶数的与幻方内以中心点为对称点的右下角对角数字进行交换；将右上区域i+j为奇数的与幻方内以中心点为对称点的左下角对角数字进行交换。（保证不同时为奇或偶即可。）
    */
    void doublyEven(vector<vector<int>> a, int n) {
        int size = n * n;
        int count = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = count++;
            }
        }

        //left upper, i+j is even, exchange with right bottom
        for (int i = 0; i < n / 2; i++) {
            int j = (i % 2 == 0) ? 0 : 1;
            for (; j < n / 2; j += 2) {
                int x = n - 1 - i;
                int y = n - 1 - j;
                int tmp = a[i][j];
                a[i][j] = a[x][y];
                a[x][y] = tmp;
            }
        }

        //right upper, i+j is odd, exchange with left bottom
        for (int i = 0; i < n / 2; i++) {
            int j = (i % 2 == 0) ? n / 2 + 1 : n / 2;
            for (; j < n; j += 2) {
                int x = n - 1 - i;
                int y = n - 1 - j;
                int tmp = a[i][j];
                a[i][j] = a[x][y];
                a[x][y] = tmp;
            }
        }
    }

    /*
    Merzirac法，即走X+Y斜步（数字按右上方顺序填入），-Y跳步（如果右上方已有数字或出了对角线，则向下移一格继续填写*/
    void odd(vector<vector<int>> a, int n) {
        int size = n * n;
        int i = 0;
        int j = n / 2;
        a[i][j] = 1;
        int count = 2;
        while (count <= size) {
            int x = i - 1;
            int y = j + 1;

            if (x < 0 && y == n) { //out of the diagnoal, go down
                x = i + 1;
                y = j;
            } else if (x < 0) {// out of row, move to the last row
                x = n - 1;
            } else if (y == n) {//out of col, move to the first row
                y = 0;
            } else if (a[x][y] != 0) { //already occupied, go down
                x = i + 1;
                y = j;
            }

            a[x][y] = count++;
            i = x;
            j = y;
        }
    }
};
