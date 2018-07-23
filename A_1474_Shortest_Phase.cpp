class Solution {
public:
    /**
     * @param k: The number of words in the article
     * @param lim: TThe minimum number of words a phrase should contain
     * @param str: The article
     * @return: Return the length of shortest phrase
     */
    int getLength(int k, int lim, vector<string> str) {
        // Write your code here
        int l=0,n=str.size(),r=--k;
        int cur=0, an=3e5;
        for(int i=0;i<=r;i++)cur += str[i].size();
        while(r<n){
            while(cur>lim && r-l>k) {
                cur -= str[l++].size();
                if(cur>=lim && cur <an) an=cur;
            }
            while(cur<lim&&r<n) {
                if(r==n-1)return an;
                cur+= str[++r].size();
            }
            if(cur == lim) return lim;
            if(cur>=lim && cur <an) an=cur;
            if(r-l==k && cur>lim) {
                if(r==n-1)return an;
                cur -=str[l++].size();
                cur +=str[++r].size();
            }
        }
        return an;
    }
};
