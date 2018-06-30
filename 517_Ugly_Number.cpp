class Solution {
public:
    /**
     * @param num: An integer
     * @return: true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // write your code here
        if(!num) return false;
        int att[3] = {2,3,5};
        for(int y:att)
            while(num % y == 0)
                num /= y;
        return num == 1;
    }
};
