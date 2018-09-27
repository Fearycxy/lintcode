class Solution {
public:
    /**
     * @param s: a string
     * @return: return a string
     */
    string removeDuplicateLetters(string &s) {
        // write your code here
        string re;
        int count[256] = {0} , visit[256] = {0};
        for(char c:s) count[c]++;
        for(char c:s){
            count[c]--;
            if(visit[c]) continue;
            while(!re.empty() && c<re.back() && count[re.back()]){
                visit[re.back()] = 0;
                re.pop_back();
            }
            re.push_back(c);
            visit[c] = 1;
        }
        return re;
    }
};
