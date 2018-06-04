/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /*
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode *build(vector<string> &expression) {
        // write your code here
        stack<ExpressionTreeNode *> opst;
        stack<ExpressionTreeNode *> datast;
        for (string s:expression) {
            if (s[0] < '0' || s[0] > '9') {
                switch (s[0]) {
                    case '(':
                        opst.push(new ExpressionTreeNode(s));
                        break;
                    case '+':
                    case '-':
                        while (!opst.empty() && opst.top()->symbol[0] != '(') {
                            build(opst, datast);
                        }
                        opst.push(new ExpressionTreeNode(s));
                        break;
                    case '*':
                    case '/':
                        while (!opst.empty() && (opst.top()->symbol[0] == '*' || opst.top()->symbol[0] == '/')) {
                            build(opst, datast);
                        }
                        opst.push(new ExpressionTreeNode(s));
                        break;
                    case ')':
                        while (opst.top()->symbol[0] != '(') {
                            build(opst, datast);
                        }
                        opst.pop();
                        break;
                }
            } else {
                auto data = new ExpressionTreeNode(s);
                datast.push(data);
            }
        }
        while (!opst.empty()) {
            build(opst, datast);
        }
        if (datast.empty()) return NULL;
        return datast.top();
    }

private:
    inline void build(stack<ExpressionTreeNode *> &opst, stack<ExpressionTreeNode *> &datast) {
        auto op = opst.top();
        opst.pop();
        auto l = datast.top();
        datast.pop();
        auto r = datast.top();
        datast.pop();
        op->left = r;
        op->right = l;
        datast.push(op);
    }
};
