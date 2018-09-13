class Solution {
public:
    /**
     * @param n: the length of strobogrammatic number
     * @return: All strobogrammatic numbers
     */
    vector<string> findStrobogrammatic(int n) {
        // write your code here
        vector<string> res;
        bool isOdd = n&1;
        string s = "";
        if(isOdd){
            for(int i=2;i<5;i++){
                s = left[i];
                dfs(n-1,s,res);
            }
        }else{
            dfs(n,s,res);
        }
        return res;
    }
    string left[5] = {"6","9","1","8","0"};
    string right[5] = {"9","6","1","8","0"};
    void dfs(int remain,string &now,vector<string>& res){
        if(remain ==0){
            res.push_back(now);
            return;
        }
        int len = remain==2?4:5;
        for(int i=0;i<len;i++){
            now = left[i]+now+right[i];
            dfs(remain-2,now,res);
            now = now.substr(1,now.size()-2);
        }
    }
};
