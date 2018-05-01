class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
     vector<int> A;
     int n;
     int re ;
     int top;
    int backPack(int m, vector<int> &A) {
        // write your code here
        n = A.size();
        re = INT_MIN;
        top = m;
        this->A= A;
        int dp[n];
         dps(0,0);
         return re;
    }
    
    void dps(int t,int value){
        if(t ==n){
            re = max(re,value);
            return;
        }
        if(value+A[t]<top){
            dps(t+1,value+A[t]);
        }
        dps(t+1,value);
    }
};//超时是必然的嘿嘿嘿
