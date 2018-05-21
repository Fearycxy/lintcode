class Solution {
public:

    static bool help(int a,int b){
        string y = to_string(a);
        string z= to_string(b);
        return y+z > z+y;
    }
    /**
     * @param nums: A list of non negative integers
     * @return: A string
     */
    string largestNumber(vector<int> &nums) {
        // write your code here
        sort(nums.begin(),nums.end(),help);
        string re = "";
        for(int a:nums){
            if(re.empty()&&a==0) continue;
            re+= to_string(a);
        }
        if(re.empty()) return "0";
        return re;
    }
};
