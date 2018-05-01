class Solution {
public:

 vector<int> num;
    int target;

    int find(int start,int end){
        int mid;
        while(start<end-1){
            mid = (start+end)/2;
            if(num[mid] == target){
                return mid;
            }else if(num[mid]<target){
                start = mid;
            }else {
                end = mid;
            }
        }
        if(num[start] == target){
            return start;
        }
        if(num[end] == target){
            return end;
        }
        return -1;
    }
    /**
     * @param A: an integer ratated sorted array and duplicates are allowed
     * @param target: An integer
     * @return: a boolean 
     */
    bool search(vector<int> &A, int target) {
        // write your code here
          // write your code here
        num = A;
        int n = A.size();
        this->target = target;
        if(n < 2){
            return n && A[0] == target;
        }
        if(A[0]<A[n-1]){
            return find(0,n-1) != -1;
        }else{
            int mid;
            int start = 0;
            int end = n-1;
            while(start<end-1){
                mid = (start+end)/2;
                if(num[mid] < num[mid-1]){
                    break;
                }else if(num[mid]<A[n-1]){
                    end = mid;
                }else {
                    start = mid;
                }
            }
            int f = find(0,mid);
            if(f != -1){
                return true;;
            }
            f = find(mid+1,n-1);
            return f!=-1;

        }
    }
};
