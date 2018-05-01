class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        int start = 0;
         vector<int> re;
        int end = A.size()-1;
        if(end == -1){
              re.push_back(-1);
            re.push_back(-1);
            return re;
        }
       
        while(start<end){
            if(A[start] != target) start++;
            if(A[end]!= target) end--;
            if(A[start] == target && A[end]== target) {
                re.push_back(start);
                 re.push_back(end);
                return re;
            }
            
        }
        if(A[start] != target){
            re.push_back(-1);
            re.push_back(-1);
            return re;
        }else{
            re.push_back(start);
            re.push_back(end);
            return re;
        }
    }
};
