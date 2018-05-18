class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        vector<string> re;
        unordered_map<string,string>mp;
        for(string &s:strs){
            string a = s;
            sort(a.begin(),a.end());
            if(mp.count(a)){
                if(mp[a]!="-1"){
                    re.push_back(mp[a]);
                    mp[a]="-1";
                }
                re.push_back(s);
            }else{
                mp[a] = s;
            }
        }
        return re;
    }
};
