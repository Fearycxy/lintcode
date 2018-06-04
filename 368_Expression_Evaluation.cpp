class Solution {
public:
    /**
     * @param expression: a list of strings
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here
                // write your code here
        stack<string> opst;
        stack<string> datast;
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
                datast.push(s);
            }
        }
        while (!opst.empty()) {
            build(opst, datast);
        }
        if (datast.empty()) return 0;
        return stoi(datast.top());
    }
private:
    inline void build(stack<string> &opst, stack<string> &datast) {
        string op = opst.top();
        opst.pop();
        int r = stoi(datast.top());
        datast.pop();
        int l = stoi(datast.top());
        datast.pop();
        switch(op[0]){
            case '*':
                op = to_string(l*r);
                break;
            case '/':
                op = to_string(l/r);
                break;
            case '-':
                op = to_string(l-r);
                break;
            case '+':
                op = to_string(l+r);
                break;
        }
        datast.push(op);
    }
};

