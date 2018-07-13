class Solution {
public:
    /**
     * @param nums1: an array
     * @param nums2: an array
     * @return:  find all the next greater numbers for nums1's elements in the corresponding places of nums2
     */
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        // Write your code here
        std::stack<int> st;
        unordered_map<int,int>mp;
        vector<int> res;
        for(int num:nums2){
            while(!st.empty() && st.top() < num){
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        for(int y:nums1){
            res.push_back(mp.count(y) ? mp[y]:-1);
        }
        return res;
    }
};
