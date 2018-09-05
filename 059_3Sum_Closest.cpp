//第二遍重做版本
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         int n = nums.size();long long re=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i = 0;i< n-2;i++){
            if(i && nums[i]==nums[i-1]) continue;
            int left = i+1,right = n-1;
            while(left<right){
                if(abs(re-target) > abs(nums[left]+nums[right]+nums[i] - target) ) re = nums[left]+nums[right]+nums[i];
                if(nums[left]+nums[right]+nums[i]>target)right--;
                else if(nums[left]+nums[right]+nums[i]<target)left++;
                else return target;
            }
        }
        return re;
    }
};
//原版
class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        // write your code here
        int re = numbers[0]+numbers[1]+numbers[2];
        int n = numbers.size();
        int tem = 0;
        sort(numbers.begin(),numbers.end());
        for(int i = 0;i<n-2;i++){
            if(i && numbers[i] == numbers[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left<right){
                tem = numbers[i]+numbers[left]+numbers[right];
                 if(tem == target){
                    return target;
                }else if(abs(tem-target)<abs(re-target)){
                    re = tem;
                }
                while(left < right && numbers[left+1] == numbers[left]) left++;
                 while(left < right && numbers[right-1] == numbers[right]) right--;
                if(tem>target) {
                     right--;
                }else if(tem<target) {
                    left++;
                }
            }
        }
        return re;
    }
};
