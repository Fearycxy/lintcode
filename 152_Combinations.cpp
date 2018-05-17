class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        // write your code here
        return help(1,n,k);
    }
private:
   vector<vector<int>> help(int start,int end,int k){
       vector<vector<int>> a;
       vector<int> tmp;
        if(start>end || k<=0|| end-start+1<k){
            return a;
        }
        if(k==1){
            for(int i =start;i<=end;i++){
                tmp.clear();
                tmp.push_back(i);
                a.push_back(tmp);
            }
            return a;
        }
        for(;start<=end-k+1;start++){
            vector<vector<int>> tm = help(start+1,end,k-1);
            for(auto s:tm){
                tmp.clear();
                tmp.push_back(start);
                tmp.insert(tmp.end(),s.begin(),s.end());
                a.push_back(tmp);
            } 
        }
        return a;
    }
};
