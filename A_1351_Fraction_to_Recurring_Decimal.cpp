class Solution {
public:
    /**
     * @param numerator: a integer
     * @param denominator: a integer
     * @return: return a string
     */
    string fractionToDecimal(int numerator, int denominator) {
        // write your code here
        string inte;
        int s1 = numerator>0?1:-1;
        int s2 = denominator>0?1:-1;
        long long a = abs((long long)numerator);
        long long b = abs((long long)denominator);
        long long front = a/b;
        inte = to_string(front);
        long long  tem = a % b;
        if(s1 * s2 <0 && (front>0 || tem >0)) inte = "-" + inte;
        if(tem ==0) return inte;
        inte.push_back('.');
        string frac;
        int pos = 0;
        unordered_map<long long,int>mp;
        while(tem !=0){
            if(mp.find(tem) != mp.end()){
                frac.insert(mp[tem] ,"(");
                frac += ')';
                break;
            }
            mp[tem] = pos;
            frac += to_string(tem*10/b);
            tem = tem*10 %b;
            pos++;
        }
        return inte+frac;
    }
};
