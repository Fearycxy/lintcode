class Solution {
public:
 vector<int> num;
 
   int faward(int * fa,int len){
       int mins = 0;
       int sum = 0;
       int maxsub = INT_MIN;
       for(int i = 0;i<len;i++){
           sum += num[i];
          
          maxsub = max(sum-mins,maxsub);
          fa[i] = maxsub;
           mins = min(sum,mins);
       }
   }
   
    int backg(int * ba,int len){
        int mins = 0;
       int sum = 0;
       int maxsub = INT_MIN;
       for(int i = 0;i<len;i++){
           sum += num[len-i-1];
           
          maxsub = max(sum-mins,maxsub);
          ba[len-i-1] = maxsub;
          mins = min(sum,mins);
       }
   }
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        // write your code here
        num = nums;
        int n = nums.size();
        if(n == 0){
            return 0;
        }if( n ==1){
            return nums[0];
        }
        int * fac = new int[n];
        faward(fac,n);
        int * bac = new int[n];
        backg(bac,n);
        int sum = INT_MIN;
        for(int i = 0;i<n-1;i++){
            sum = max(sum,fac[i]+bac[i+1]);
        }
        delete[] fac;
        delete[] bac;
        return sum;
    }
};
