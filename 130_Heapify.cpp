//第二遍重做版
class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        // write your code here
         // write your code here
        for(int i =1;i<A.size();i++){
            int cur = i;
            while(cur && A[(cur-1)/2] > A[cur]){
                swap(A[(cur-1)/2],A[cur]);
                cur = (cur-1)/2;
            }
        }
    }
};

//version1
class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        // write your code here
         // write your code here
        int n = A.size();
        for(int j = n-1/2;j>=0;j--){
            int i = j;
            while(i<n){
                int small = i;
                if((i*2+1)<n && A[i*2+1]<A[small]) small = i*2+1;
                if((i*2+2)<n && A[i*2+2]<A[small]) small = i*2+2;
                if(i == small){
                    break;
                }
                swap(A[i],A[small]);
                i = small;
            }
        }
    }
};


