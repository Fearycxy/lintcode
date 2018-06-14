//solution 1 http://www.cnblogs.com/grandyang/p/5162678.html
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long res =0,sum = 0;
        multiset<long long> mul = {0};
        for(int i:nums){
            sum+=i;
            res += distance(mul.lower_bound(sum-upper),mul.upper_bound(sum-lower));
            mul.insert(sum);
        }
        return res;
    }        
};

//solution2 https://blog.csdn.net/qq508618087/article/details/51435944
class Solution {
public:

    int mergeSort(vector<int> &sums,int start,int end,int lower ,int upper){
        cout << start <<"," <<end <<endl;
        if(start>=end-1) return 0;
        int mid = start + ((end-start)>>1),l = mid,r= mid;
        int count = mergeSort(sums,start,mid,lower,upper)
        + mergeSort(sums,mid,end,lower,upper);
        for(int i =start;i<mid;i++){
            while(l<end && sums[l]-sums[i]<lower) ++l;
            while(r<end && sums[r]-sums[i]<=upper) ++r;
            count += r-l;
        }
        inplace_merge(sums.begin(),sums.begin()+mid,sums.end());
        return count;
    }   
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
         vector<int> sum(nums.size()+1);
        for(int i=0; i<nums.size(); ++i) sum[i+1]=nums[i]+sum[i];
        return mergeSort(sum,0,sum.size(),lower,upper);
    }        
};
