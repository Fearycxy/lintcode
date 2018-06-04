public class MinStack {
     private Stack<Integer> stack1; // original stack
    private Stack<Integer> stack2; // min stack
    public MinStack() {
        stack1 = new Stack();
        stack2 = new Stack();
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    public void push(int number) {
      stack1.push(number);
      if(stack2.isEmpty()){
          stack2.push(number);
      }else{
          stack2.push(Math.min(number,stack2.peek()));
      }
        // write your code here
    }

    /*
     * @return: An integer
     */
    public int pop() {
        stack2.pop();
       return stack1.pop();
        // write your code here
    }

    /*
     * @return: An integer
     */
    public int min() {
        return stack2.peek();
        // write your code here
    }
}
