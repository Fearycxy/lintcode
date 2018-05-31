class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        vector<int> re;
        if(!k || nums.empty()) return re;
        multiset<int> small;
        multiset<int> big;
        for(int i =0;i<k;i++) big.insert(nums[i]);
        while(big.size()>small.size()){
            small.insert(*big.begin());
            big.erase(big.begin());
        }
        int last = *(--small.end());
        re.push_back(last);
        for(int t =k;t<n;t++){
            int er = nums[t-k];
            if(er <=last){
                small.erase(small.find(er));
            }else{
                big.erase(big.find(er));
            }
            if(nums[t]<=last){
                small.insert(nums[t]);
            }else{
                big.insert(nums[t]);
            }
            while(big.size()+1<small.size()){
                big.insert(*(--small.end()));
                small.erase(--small.end());
            }
            while(big.size()>small.size()){
                small.insert(*big.begin());
                big.erase(big.begin());
            }
            last = *(--small.end());
            re.push_back(last);
        }
        return re;
    }
};
