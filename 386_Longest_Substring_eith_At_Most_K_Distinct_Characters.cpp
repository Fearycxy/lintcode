class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        int re = 0,L=0,R=0,n=s.size();
        unordered_map<char ,int> mp;
        while(R<n){
            mp[s[R]]++;
            while(mp.size()>k){
                mp[s[L]]--;
                if(mp[s[L]]==0) mp.erase(mp.find(s[L]));
                L++;
            }
            re = max(re,R-L+1);
            R++;
        }
        return re;
    }
};
