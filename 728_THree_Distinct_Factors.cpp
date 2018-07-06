class Solution {
public:
    /**
     * @param n: the given number
     * @return:  return true if it has exactly three distinct factors, otherwise false
     */
    bool isThreeDisctFactors(long long n) {
        // write your code here
        long long y = sqrt(n);
        if(n==y*y && isPrime(y)) return true;
        return false;
    }
private:

    bool isPrime(long long y){
        if(y == 2) return true;
        long long ky = sqrt(y);
	    for(long long i = 2;i<=ky;i++){
	        if(y%i==0) return false;
	    }
	    return true;
    } 
};
