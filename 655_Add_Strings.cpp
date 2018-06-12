class Solution {
public:
    /**
     * @param num1: a non-negative integers
     * @param num2: a non-negative integers
     * @return: return sum of num1 and num2
     */
    string addStrings(string &num1, string &num2) {
        // write your code here
        string &ls = num1.size() < num2.size() ? num2:num1;
        string &ss = num1.size() < num2.size() ? num1:num2;
        int l = ls.size();int s = ss.size();
        string an;int y =0;
        for(int i =1;i<=l;i++){
            int a1 = i<=s? (ss[s-i]-'0'):0;
            int a2 = ls[l-i]-'0';
            int u = a1+a2+y;
            if(u >=10){
                y = 1;
                u = u%10;
            }else{
                y = 0;
            }
            an.insert(an.begin(),'0'+u);
        }
        if(y) an.insert(an.begin(),'1');
        return an;
    }
};
