class Solution {
public:
    /**
     * @param num: a string
     * @param k: an integer
     * @return: return a string
     */
    string removeKdigits(string &num, int k) {
        // write your code here
         int keep = num.size() - k;
         string re;
         for(char c:num){
             while(k && !re.empty() && re.back() > c){
                 re.pop_back();
                 k--;
             }
             re.push_back(c);
         }
         re.resize(keep);
         while(!re.empty() && re[0] =='0' ) re.erase(re.begin());
         return re.empty()?"0":re;
    }
};
