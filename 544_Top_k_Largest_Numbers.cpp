//第二编重做版
class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        int left = 0, right = nums.size();
        while(right != k){
            int begin = left,end = right, pivot = nums[begin];
            while(begin < end){
                while(begin < end && nums[--end] <= pivot);
                nums[begin] = nums[end];
                while(begin < end && nums[++begin] >= pivot);
                nums[end] = nums[begin];
            }
            nums[begin] = pivot;
            if(begin == k) break;
            else if(begin < k)left = begin+1;
            else right = begin;
        }
        sort(nums.begin(),nums.begin()+k,greater<int>());
        return vector<int>(nums.begin(),nums.begin()+k);
    }
};


//first version
class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        // write your code here
        vector<int> an;
        find(an,nums,0,nums.size()-1,k);
        return an;
    }
    
    void find(vector<int> &an,vector<int>&nums,int s,int e,int k){
        if(0==k) return;
        int i = s-1;
        for(int j = s;j<=e;j++)
            if(nums[j] < nums[e]) swap(nums[++i],nums[j]);
        swap(nums[i+1],nums[e]);
        if(e-i>k)find(an,nums,i+2,e,k);
        else{
            sort(nums.begin()+i+1,nums.begin()+e+1,greater<int>());
            an.insert(an.end(),nums.begin()+i+1,nums.begin()+e+1);
            find(an,nums,s,i,k - (e-i));
        }
    }
};
