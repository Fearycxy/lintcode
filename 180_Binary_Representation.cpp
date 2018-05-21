class Solution {
public:
    /**
     * @param n: Given a decimal number that is passed in as a string
     * @return: A string
     */
    string binaryRepresentation(string &n) {
        // write your code here
        int a = stoi(n.substr(0,n.find('.')));
        double b = stod(n.substr(n.find('.')));//原来可以这样哈哈哈
        
        string intpart = a>0?"":"0";
        while(a>0){
            int t = a %2;
            intpart =to_string(t)  + intpart;
            a >>= 1;
        }
        if(b == 0){
            return intpart;
        }
        intpart += ".";
        string decpart = "";
        while( b>0){
            if (decpart.size() > 32) return "ERROR";
            double d = b*2;
            if(d>=1){
                 decpart += "1";
                 b = d - 1;
            }else{
                decpart +="0";
                b = d;
            }
            
        }
        return intpart+decpart;
    }
};
