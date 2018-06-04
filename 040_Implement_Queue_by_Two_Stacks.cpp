class MyQueue {
public:
std::stack<int > s1;
stack<int> s2;
    MyQueue() {
        // do intialization if necessary
    }

    /*
     * @param element: An integer
     * @return: nothing
     */
    void push(int element) {
        // write your code here
        s2.push(element);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int tmp = top();
        s1.pop();
        return tmp;
    }

    /*
     * @return: An integer
     */
    int top() {
        if(s1.empty()) adjust();
          return s1.top();
        // write your code here
    }
private:
    void adjust(){
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
};
