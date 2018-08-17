class Solution {
public:
    /**
     * @param dict: an array of n distinct non-empty strings
     * @return: an array of minimal possible abbreviations for every word
     */
    vector<string> wordsAbbreviation(vector<string> &dict) {
        // write your code here
        int n = dict.size();
        vector<int> pre(n,1);
        vector<string> an(n);
        for(int i=0;i<n;i++) an[i] = getPre(dict[i],1);
        for(int i=0;i<n;i++){
            while(true){
                vector<int> vec;
                for(int j=i+1;j<n;j++){
                    if(an[j]==an[i]){
                        vec.push_back(j);
                    }
                }
                if(vec.empty()) break;
                vec.push_back(i);
                for(int d:vec) an[d] = getPre(dict[d],++pre[d]);
            }
        }
        return an;
    }
    
    string getPre(string &s,int pre){
        return (s.size() - pre)<=2?s:s.substr(0,pre) + to_string(s.size()-pre-1) + s.back();
    }
};
