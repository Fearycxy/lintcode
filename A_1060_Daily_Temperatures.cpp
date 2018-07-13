class Solution {
public:
    /**
     * @param temperatures: a list of daily temperatures
     * @return: a list of how many days you would have to wait until a warmer temperature
     */
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        // Write your code here
        stack<int> st;int n = temperatures.size();
        vector<int> res(n,0);
        for(int j=n-1;j>=0;j--){
            while(!st.empty()&&temperatures[st.top()] <=temperatures[j]) st.pop();
            if(!st.empty())res[j] = st.top() - j;
            st.push(j);
        }
        return res;
    }
};
