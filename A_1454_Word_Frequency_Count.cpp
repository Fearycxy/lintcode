class Solution {
public:
    /**
     * @param s: The string s
     * @param excludeList: The excludeList
     * @return: Return the most frequent words
     */
    vector<string> getWords(string &s, vector<string> &excludeList) {
        // Write your code here
        unordered_map<string,int>mp;
        string cur;
        int len = 0;
        vector<string> an;
        for(char c:s){
            if(c>='A' && c <= 'Z'){
                c = c + 'a' -'A';
            }
            if(c>='a' && c <= 'z'){
               cur += c;
            }else{
                if(cur.empty()) continue;
                if(mp[cur] == -1 || find(excludeList.begin(),excludeList.end(),cur) != excludeList.end()){
                   mp[cur] = -1;
                    cur = "";
                    continue;
                }
                mp[cur]++;
                if(mp[cur]>=len){
                    if(mp[cur] > len){
                        an.clear();
                    }
                    an.push_back(cur);
                    len = mp[cur];
                }
                cur = "";
            }
        }
        sort(an.begin(),an.end());
        return an;
        
    }
};
