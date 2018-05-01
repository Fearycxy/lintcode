class Solution {
public:
    /**
     * @param str: A string
     * @return: An integer
     */
       int atoi(string str) {
        // write your code here
        int sign = 1, base = 0, i = 0;
        while (str[i] == ' ') { i++; }
        if (str[i] == '-' || str[i] == '+') {
            sign = str[i++] == '+' ? 1 : -1;
        }
        while (str[i] >= '0' && str[i] <= '9') {
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            base  = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};
