class Solution {
public:
    /**
     * @param str: the origin string
     * @return: the start and end of every twitch words
     */
    vector<vector<int>> twitchWords(string &str) {
        // Write your code here
        char last =1;
        int s = 0;
        vector<vector<int>> re;
        for(int i=0;i<str.size();i++){
            if(str[i]!=last){
                if(i-s>=3){
                    re.push_back({s,i-1});
                }
                last = str[i];
                s = i;
            }
        }
        if(str.size()-s>=3) re.push_back({s,str.size()-1});
        return re;
    }
};
