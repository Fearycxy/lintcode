class Solution {
public:
    
    /*
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        // write your code here
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> an;
        auto it1 = nums1.begin(),it2 = nums2.begin();
        while(it1 != nums1.end() && it2 != nums2.end()){
            if(*it1 < *it2) it1++;
            else if(*it1 > *it2) it2++;
            else{
                an.push_back(*it1);
                it1++;
                it2++;
            }
        }
        an.erase(unique(an.begin(),an.end()),an.end());
        return an;
    }
};
