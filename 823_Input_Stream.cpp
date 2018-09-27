class Solution {
public:
    /**
     * @param inputA: Input stream A
     * @param inputB: Input stream B
     * @return: The answer
     */
    string inputStream(string &inputA, string &inputB) {
        // Write your code here
        return getstr(inputA) == getstr(inputB)?"YES":"NO";
    }
    
    string getstr(string s){
        string a;
        for(char c:s){
            if(c=='<'){
                if(!a.empty()) a.pop_back();
            }else{
                a.push_back(c);
            }
        }
        return a;
    }
};
