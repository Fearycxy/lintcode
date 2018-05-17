class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> nums) {
        // write your code here
        int start = 0;
        int end = nums.size()-1;
        if(nums[0]<nums[end]) return nums[0];
        while(start <end-1){
            int mid = (start+end)>>1;
            if(nums[mid]<nums[end]|| nums[mid] <nums[start]){
                end = mid;
            }else if(nums[mid]>nums[start]|| nums[mid] > nums[end]){
                start = mid;
            }else{
                if(mid - start <2){
                    start = mid;
                }else if(end - mid <2){
                    end = mid;
                }else
                return min(findMin(vector<int>(nums.begin()+start, nums.begin()+mid)),
                findMin(vector<int>(nums.begin()+mid, nums.begin()+end+1)));
            }
        }
        return nums[end];
    }
};


//九章算法
//http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
         int lo = 0;
        int hi = num.size()-1;
        while(lo<hi){
            int mid = lo + (hi - lo)/2;
            if(num[mid]>num[hi]){
                lo = mid+1;
            }else if(num[mid]<num[hi]){
                hi = mid;
            }else{
                hi--;
            }
        }
        return num[lo];
        
       /* 
        int st = 0;
        int ed = num.size()-1;
        while(st<ed){
            int mid = st+(ed-st)/2;
            if(num[mid] > num[ed]){
                st = mid+1;
            }else if(mid[mid] < num[ed]){
                ed = mid;
            }else {
                ed--;
            }
        }
        return num[st];
        */
    }
};
