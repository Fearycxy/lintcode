class Solution {
public:
struct cmp{
    bool operator() (string a,string b){
        return a+b < b+a;
    }
};
    /**
     * @param nums: n non-negative integer array
     * @return: A string
     */
    string minNumber(vector<int> &nums) {
        // write your code here
        vector<string> vec;
        for(int i:nums) if(i)vec.push_back(to_string(i));
        if(vec.empty()) return "0";
        sort(vec.begin(),vec.end(),cmp());
        string re;
        for(string &s:vec) re += s;
        return re;
    }
};
