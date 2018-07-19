class Solution {
public:
    /**
     * @param S: a string
     * @param words: a dictionary of words
     * @return: the number of words[i] that is a subsequence of S
     */
    int numMatchingSubseq(string &S, vector<string> &words) {
        // Write your code here
        int cnt =0;
        unordered_map<char,queue<string>>mp;
        for(auto &s:words)mp[s[0]].push(s);
        for(char c:S){
            auto &que = mp[c];
            int n = que.size();
            for(int u =0;u<n;u++){//重点，这里不能是判断!que.empty()
                string a = que.front();
                que.pop();
                if(a.size() ==1) cnt++;
                else mp[a[1]].push(a.substr(1));
            }
        }
        return cnt;
    }
};
