class Solution {
public:
vector<int> nums;
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        if (nums.empty()) return 0;
         this->nums = nums;
        int len = nums.size();
        return helper(0, len - 1, (len + 1) / 2);
    }

private:
    int helper(const int low,const int high,int size){
        int t = nums[low];
        int left = low;
        int right = high;
        while(left<right){
            while(left<right && nums[right]>=t){
                right--;
            }
            if(left<right){
                swap(nums[left],nums[right]);
            }
            while(left<right && nums[left]<=t){
                left++;
            }
             if(left<right){
                swap(nums[left],nums[right]);
            }
        }
        cout <<endl;
        if((left-low+1) == size){
            return nums[left];
        }else if((left-low+1)>size){
            return helper(low,left-1,size);
        }else{
            return helper(left+1,high,size-(left-low+1));
        }
        
    }
};
