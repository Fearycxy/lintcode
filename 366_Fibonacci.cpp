class Solution {
public:
    /**
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int a = 0;
        int b = 1;
        while(n-->1){
            b = a+b;
            a = b-a;
        }
        return a;
    }
};

//matrix version
class Matrix {
public:
    unordered_map<int, unordered_map<int, int>> value;
    int row, col;

    Matrix(int row, int col) {
        this->row = row;
        this->col = col;
    }

    Matrix operator*(Matrix &matrix) {
        Matrix ret(row, matrix.col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < matrix.col; j++) {
                for (int k = 0; k < col; k++) {
                    ret.value[i][j] = ret.value[i][j] + value[i][k] * matrix.value[k][j];
                }
            }
        }
        return ret;
    }

    Matrix power(int n) {
        Matrix ret(row, col);
        for (int i = 0; i < col; i++) ret.value[i][i] = 1;
        Matrix matrix(*this);
        while (n > 0) {
            if (n % 2 == 1) {
                ret = ret * matrix;
            }
            n >>= 1;
            matrix = matrix * matrix;
        }
        return ret;
    }
};

class Solution {
public:
    /*
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n) {
        // write your code here
        if (n == 1 || n == 2) {
            return n - 1;
        }
        Matrix A(2, 2);
        Matrix B(2, 1);
        A.value[0][0] = 1;
        A.value[0][1] = 1;
        A.value[1][0] = 1;
        A.value[1][1] = 0;
        B.value[0][0] = 1;
        B.value[1][0] = 0;
        return (A.power(n - 2) * B).value[0][0];
    }
};
