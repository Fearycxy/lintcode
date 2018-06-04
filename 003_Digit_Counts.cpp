class Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
 int digitCounts(int k, int n) {
    // write your code here
    int result = 0;
    for(int i = 0;i<=n;i++){
        int s = i;
        if(s == 0 && k == 0){
            result ++;
        }
        while(s){
            if(s%10 == k){
                result ++;
            }
            s /= 10;
        }

    }
    return result;
}
 
};
