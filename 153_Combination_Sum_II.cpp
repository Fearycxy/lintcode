class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
     typedef vector<int> VI;
     int n;
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<VI> re;VI tmp;
        this->n = num.size();
        sort(num.begin(),num.end());
        help(re,tmp,0,target,num,INT_MIN);
        return re;
    }
    
    void help(vector<VI> &re,VI tmp,int target,int sum,VI &num,int last){
        if(target==n){
            return;
        }
        int t = num[target];
        if(t > last && t <= sum){
            tmp.push_back(t);
            if(t == sum){
                re.push_back(tmp);
            }else{
                help(re,tmp,target+1,sum -t,num,INT_MIN);
            }
             tmp.pop_back();
        }
        help(re,tmp,target+1,sum,num,t);
       
    }
};
