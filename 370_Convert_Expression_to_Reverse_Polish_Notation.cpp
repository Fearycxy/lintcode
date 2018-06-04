class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        stack<string> opst;
        vector<string> datast;
        for (string s:expression) {
            if (s[0] < '0' || s[0] > '9') {
                switch (s[0]) {
                    case '(':
                        opst.push(s);
                        break;
                    case '+':
                    case '-':
                        while (!opst.empty() && opst.top()[0] != '(') {
                            build(opst, datast);
                        }
                        opst.push(s);
                        break;
                    case '*':
                    case '/':
                        while (!opst.empty() && (opst.top()[0] == '*' || opst.top()[0] == '/')) {
                            build(opst, datast);
                        }
                        opst.push(s);
                        break;
                    case ')':
                        while (opst.top()[0] != '(') {
                            build(opst, datast);
                        }
                        opst.pop();
                        break;
                }
            } else {
                datast.push_back(s);
            }
        }
        while (!opst.empty()) {
            build(opst, datast);
        }
        return datast;
    }
private:
    inline void build(stack<string> &opst, vector<string> &datast) {
        string op = opst.top();
        opst.pop();
        datast.push_back(op);
    }
};
