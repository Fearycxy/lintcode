class Solution {
public:
    /**
     * @param num: a string contains only digits 0-9
     * @param target: An integer
     * @return: return all possibilities
     */
    vector<string> addOperators(string &num, int target) {
        // write your code here
        vector<string> res;
        help(num,target,0,0,"",res);
        return res;
    }
private:
    void help(string &num,int target,long long diff,long long last,string pre,vector<string> &res){
        if(num.empty() && last == target) res.push_back(pre);
        for(int i=1;i<=num.size();i++){
            string cur = num.substr(0,i);
            if(cur.size()>1 && cur[0]== '0') return;
            string next = num.substr(i);
            long long c = stoll(cur);
            if(pre.size()){
                 help(next,target,c,last + c,pre + "+" + cur,res);
                 help(next,target,-c,last - c,pre + "-" + cur,res);
                 help(next,target,diff*c,last - diff + diff * c,pre + "*" + cur,res);
            }else{
                help(next,target,c,c,cur,res);
            }
        }
    }
};
