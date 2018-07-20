class Solution {
public:
    /**
     * @param m: an integer
     * @param n: an integer
     * @return: the total number of unlock patterns of the Android lock screen
     */
    int numberOfPatterns(int m, int n) {
        // Write your code here
        bool flag[9]={0};
        int re=0;
        for(int i=0;i<9;i++){
            dfs(flag,i,re,1,m,n);
        }
        return re;
    }
    
    void dfs(bool *flag,int cur,int &re,int cnt,int m,int n){
        if(cnt>n) return;
        if(cnt>=m)re++;
        flag[cur] = true;
        for(int i=0;i<9;i++){
            if(!flag[i]){
                bool can = i==4 || cur==4;
                if((i +cur)%2==1) can = true;
                if(i%2==1&&cur%1==0&&(i+cur)!=8) can = true;
                if(can ||flag[(i+cur)>>1]) dfs(flag,i,re,cnt+1,m,n);
            }
        }
        flag[cur] = false;
    }
};
