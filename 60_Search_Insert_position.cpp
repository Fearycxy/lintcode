class Solution {
public:
vector<int> num; 
     int target;
     int search(int left,int right){
         int mid = (left+right)/2;
         if(mid==left){
             cout << left <<endl;
              cout << right <<endl;
              if(num[right]<target){
                  return right+1;
              }
             if(num[left]>=target){
                return left;
             }
             return right;
         }
         if(num[mid]>target){
             return search(left,mid);
         }else if(num[mid]<target){
             return search(mid,right);
         }else{
             return mid;
         }
     }
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &A, int target) {
        num = A;
        // write your code here
        this->target =target;
        int left = 0;
        int right = A.size()-1;
        if(right == -1){
            return 0;
        }
        return search(left,right);
    }
};
