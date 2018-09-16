#define MOD % 10000
class Solution {
public:
    /**
     * @param n: an integer
     * @return: return a string
     */
    string lastFourDigitsOfFn(int n) {
        // write your code here
        if (n == 0) return "0";
        vector<vector<int>> matrix = {{1, 1}, {1, 0}};
        power(matrix, n - 1);
        return to_string(matrix[0][0]);
    }

private:
    void power(vector<vector<int>>& F, int n) {
        if (n == 0 || n == 1) {
            return;
        }
        power(F, n >> 1);
        multiply(F, F);
        if (n & 1) {
            vector<vector<int>> M = {{1, 1}, {1, 0}};
            multiply(F, M);
        }
    }

    void multiply(vector<vector<int>>& F, vector<vector<int>>& M) {
        int x = (F[0][0] * M[0][0] MOD + F[0][1] * M[1][0] MOD) MOD;
        int y = (F[0][0] * M[0][1] MOD + F[0][1] * M[1][1] MOD) MOD;
        int z = (F[1][0] * M[0][0] MOD + F[1][1] * M[1][0] MOD) MOD;
        int w = (F[1][0] * M[0][1] MOD + F[1][1] * M[1][1] MOD) MOD;
        F = {{x,y},{z,w}};
    }
};
