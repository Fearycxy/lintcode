class Solution {
public:
    /*
     * @param num: An integer
     * @return: An integer
     */
    int countOnes(int num) {
        // write your code here
        int re =0;
        while(num){
            int s = num & -num;
            num -= s;
            re++;
        }
        return re;
    }
};
