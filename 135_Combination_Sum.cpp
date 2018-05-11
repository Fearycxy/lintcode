class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    typedef vector<int> VI;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<VI> re;
        VI cur;
        sort(candidates.begin(),candidates.end());
        help(0,candidates,target,cur,re);
        return re;
    }
    
    int help(int index,VI &candidates,int sum,VI cur,vector<VI> &re){
        while(sum>0){
            if(index+1<candidates.size()){
                help(index+1,candidates,sum,cur,re);
            }
            sum -= candidates[index];
            cur.push_back(candidates[index]);
             if(sum <= 0) {
                 if(sum == 0)re.push_back(cur);
                 break;
             }
        }
       
        
    }
};
