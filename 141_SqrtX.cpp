class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        long long s = x >>1;
        while(s * s > x){
            s =s >>1;
        }
        while(s * s <= x){
            s +=1;
        }
        return s-1;
    }
};
