class Solution {
public:
    vector<int> nums;
    int n = 0;
    inline int frontmax(int* vec){
          int mins = 0;
        int sum = 0;
        int maxs = INT_MIN;
        for(int i =0;i<n;i++){
            sum += nums[i];
            maxs = max(maxs,sum-mins);
            vec[i] = maxs;
            mins = min(sum,mins);
        }
    }
    inline int bacmax(int* vec){
          int mins = 0;
        int sum = 0;
        int maxs = INT_MIN;
        for(int i =n-1;i>=0;i--){
            sum += nums[i];
            maxs = max(maxs,sum-mins);
            vec[i] = maxs;
            mins = min(sum,mins);
        }
    }
    inline int bacmin(int* vec){
          int maxs = 0;
        int sum = 0;
        int minv = INT_MAX;
        for(int i =n-1;i>=0;i--){
            sum += nums[i];
            minv = min(minv,sum-maxs);
            vec[i] = minv;
            maxs = max(sum,maxs);
        }
    }
     inline int frontmin(int* vec){
          int maxs = 0;
        int sum = 0;
        int minv = INT_MAX;
        for(int i =0;i<n;i++){
            sum += nums[i];
            minv = min(minv,sum-maxs);
            vec[i] = minv;
            maxs = max(sum,maxs);
        }
    }
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two substrings
     */
    int maxDiffSubArrays(vector<int> &nums) {
        // write your code here
     n = nums.size();
        this -> nums = nums;
        int frontMax[n];
        frontmax(frontMax);
        int frontMin[n];
        frontmin(frontMin);
        int bacMax[n];
        bacmax(bacMax);
        int bacMin[n];
        bacmin(bacMin);
        int re = 0;
        for(int i = 0;i<n-1;i++){
            re = max(re,abs(frontMax[i]-bacMin[i+1]));
             re = max(re,abs(bacMax[i+1]-frontMin[i]));
        }
        return re;
    }
};
