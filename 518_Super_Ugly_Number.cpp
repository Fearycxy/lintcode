class Solution {
public:
    /**
     * @param n: a positive integer
     * @param primes: the given prime list
     * @return: the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        // write your code here
        int m = primes.size();
        vector<int> vec = {1};
        vector<int> gaze(m,0);
        vector<int> gay(m,0);
        for(int i =0;i<n;i++){
            int mimz = INT_MAX;
            for(int i=0;i<m;i++){
                gay[i] = primes[i]*vec[gaze[i]];
                if(gay[i] < mimz){
                    mimz = gay[i];
                }
            }
            for(int i=0;i<m;i++){
                if(mimz== gay[i]){
                    gaze[i]++;
                }
            }
            vec.push_back(mimz);
        }
        return vec[n-1];
    }
};
