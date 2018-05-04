class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        // write your code here
        int n = A.size();
        vector<int > dp;
        dp.push_back(0);//dp[x]表示第x步可以到达的最远的节点
        for(int i =0;i<n;i++){
            int m = dp.size();
            for(int f=0;f<m;f++){
                if(i<=dp[f]){
                    int s =i+A[i];
                    if(s>=n-1){
                        return f+1;
                    }
                    if(f==m-1){
                        dp.push_back(s);
                    }else{
                        dp[f+1] = max(dp[f+1],s);
                    }
                    break;
                }
            }
            
        }
        return -1;
    }
};

//http://fisherlei.blogspot.com/2012/12/leetcode-jump-ii.html dijkstra最短路径思路更简洁，O(n)
class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        // write your code here
        int n = A.size();
        if(n<=1){
            return 0;
        }
        int start =0,end = 0;
        int maxs = 0;
        int re = 0;
        while(end<n){
            re++;
            for(int i = start;i<=end;i++){
                maxs =max(maxs,A[i]+i); 
                if(maxs >=n-1){
                  return re;   
                }
                
            }
            if(maxs>end){
                start = end+1;
                end = maxs;
            }else{
                return -1;
            }
        }
        return -1;
    }
};
