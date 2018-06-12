class Solution {
public:
    /**
     * @param input: an abstract file system
     * @return: return the length of the longest absolute path to file
     */
    int lengthLongestPath(string &input) {
        // write your code here
        stringstream ss(input);
        string s;
        int an=0;
        unordered_map<int,int> mp;
        mp[0]=0;
        while(getline(ss,s)){
            int level = s.find_last_of('\t')+1;
            int len = s.substr(level).size();
            if(s.find('.') != -1){
                an = max(an,mp[level-1] + len);
            }else{
                mp[level] = mp[level-1]+1+len;
            }
            
        }
        return an;
    }
};
