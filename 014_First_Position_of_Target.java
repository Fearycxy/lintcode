class Solution {
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     * 
     *
     */
     
     int first = 0;
     int last = 0;
    public int binarySearch(int[] nums, int target) {
        if(nums[0]>target || nums[nums.length-1] < target){
            return -1;
        }
        if(nums[nums.length-1]  == target){
            return nums.length-1;
        }
        if(nums[0] == target){
            return 0;
        }
        last = nums.length-1;
        int l = binarySearchs(nums,target);
        while(l>0 && nums[l-1] == target){
           l--;
        }
        return l;
        //write your code here
    }
    
      public int binarySearchs(int[] nums, int target) {
          while((last -first) > 1){
        int middle = (first + last)/2;
        if(nums[middle] == target){
            return middle;
        }else if(nums[middle+1] == target){
            return middle+1;
        }
        if(nums[middle] < target){
            first = middle;
        }else{
            last = middle;
        }
          }
       return -1;
        //write your code here
    }
}
