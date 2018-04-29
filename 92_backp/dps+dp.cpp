class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
     vector<int> A;
     int n;
    vector<vector<int>>dp;
    int backPack(int m, vector<int> &A) {
        // write your code here
        n = A.size();
        this->A= A;
        
         for(int i =0;i<n+1;i++){
             dp.push_back(vector<int>(m+1,-1));
         }
         return dps(0,m);;
    }
    
    int dps(int t,int value){
       
        if(dp[t][value]>=0){
            return dp[t][value];
        }
        int va = INT_MIN;
         if(t ==n){
            va  = 0;
        }else if(value<A[t]){
           va =  dps(t+1,value);
        }else{
            va = max(dps(t+1,value),A[t]+dps(t+1,value-A[t]));
        }
        dp[t][value] = va;
        return va;
    }
};//加一个dp数组存储搜索结果的小优化，就ac啦！
