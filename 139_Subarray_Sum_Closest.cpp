class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> &nums) {
        // write your code here
        vector<int> re{0,0};
        map<int,int> mp;
        mp[0] = -1;
        int i = 0,sum = 0,mins = INT_MAX;
        for(int p:nums){
            sum += p;
            auto cur = mp.lower_bound(sum);
            if(cur = mp.end()) cur--;
            auto fur = cur;
            if(fur != mp.begin()) fur -- ;
            int f= abs(fur->first - sum);
            int d = abs(cur->first - sum);
            if(f<d){
                cur = fur;
                d = f;
            }
            if(d<mins){
                re[0] = cur->second+1;
                re[1] = i;
                mins = d;
                if(!d) return re;
            }
            mp[sum] = i;
            i++;
        }
        return re;
        
    }
};
