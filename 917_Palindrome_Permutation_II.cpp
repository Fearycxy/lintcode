class Solution {
public:
    /**
     * @param s: the given string
     * @return: all the palindromic permutations (without duplicates) of it
     */
    vector<string> generatePalindromes(string &s) {
        // write your code here
        unordered_map<char,int>mp;
         vector<string> re;
        for(char c:s)mp[c]++;
        string mid,t;
        for(auto &it:mp){
            if (it.second % 2 == 1) mid += it.first;
            t += string(it.second / 2, it.first);
            if (mid.size() > 1) return re;
        }
        dfs(re,mid,0,t);
        return re;
    }
    
private:
    void dfs(vector<string> &re, string &mid,int start,string &t){
        if(start >= t.size()){
            re.push_back(t+mid+string(t.rbegin(), t.rend()));
            return;
        }
        for(int i = start;i<t.size();i++){
            if(i>start && t[i] == t[start]) continue;
            swap(t[start],t[i]);
            dfs(re,mid, start +1,t);
            swap(t[start],t[i]);
        }
    }
};
