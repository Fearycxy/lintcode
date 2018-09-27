class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string re;
        for(auto &y:strs){
            re+= to_string(y.size())+'/' + y;
        }
        return re;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> vec;
        int l = 0 ,r = 0, n =str.size();
        while(!str.empty()){
            int in = stoi(str.substr(0,str.find('/')));
            vec.push_back(str.substr(str.find('/')+1,in));
            str = str.substr(str.find('/') + in+1);
        }
        return vec;
    }
};
