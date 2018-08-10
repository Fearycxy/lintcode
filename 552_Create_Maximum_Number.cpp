class Solution {
public:
    /**
     * @param nums1: an integer array of length m with digits 0-9
     * @param nums2: an integer array of length n with digits 0-9
     * @param k: an integer and k <= m + n
     * @return: an integer array
     */
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        // write your code here
        int m = nums1.size(), n = nums2.size();
        vector<int> an;
        for(int i = max(0, k - n); i <= min(k, m); ++i){
            an = max(an,merge(maxVec(nums1,i),maxVec(nums2,k-i)));
        }
        return an;
    }
    
    inline vector<int> maxVec(vector<int> &v,int k){
        vector<int> re;
        int drop = v.size() - k;
        for(int i:v){
            while(drop && re.size() && re.back() <i){
                re.pop_back();
                drop--;
            }
            re.push_back(i);
        }
        re.resize(k);
        return re;
    }
    
    inline vector<int> merge(vector<int> a,vector<int> b){
        vector<int> re;
        while(a.size() + b.size()){
            vector<int> &tem = a>b ? a:b;
            re.push_back(tem[0]);
            tem.erase(tem.begin());
        }
        return re;
    }
    
};
