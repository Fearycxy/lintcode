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
