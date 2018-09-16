class Solution {
public:
    /**
     * @param k: The k
     * @param a: The A
     * @param b: The B
     * @return: The answer
     */
    string addition(int k, string &a, string &b) {
        // Write your code here
        int m = a.size()-1, n = b.size()-1,bt = 0;
        string op;
        while(m >=0 || n>=0 || bt){
            if(m>=0){
                bt += a[m--]-'0';
            }
            if(n>=0){
                bt += b[n--]-'0';
            }
            op = to_string(bt%k)+op;
            bt /= k;
        }
        if(op == "0") return op;
        int j =0;
        while(op[j]=='0') j++;
        return op.substr(j,op.size()-j);
    }
};
