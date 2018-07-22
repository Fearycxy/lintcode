class Solution {
public:
    /**
     * @param S: a string
     * @param K: a integer
     * @return: return a string
     */
    string licenseKeyFormatting(string &S, int K) {
        // write your code here
        int str_len = S.size();
        for(int i = 0; i < S.size(); i++)
            if(S[i] == '-') str_len--;
        int index = K - str_len % K;
        str_len = str_len + (str_len - 1) / K;
        string result("\0", str_len);
        int j = 0;
        
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '-')  continue;
            
            if(S[i] <= 'z' && S[i] >= 'a') result[j] = S[i] - 'a' + 'A';
            else result[j] = S[i];
            index++;
            j++;
            if(index % K == 0 && j < str_len - 1) result[j++] = '-';
        }
        
        return result;
    }
};
