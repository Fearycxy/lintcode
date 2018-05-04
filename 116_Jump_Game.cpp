class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        int n = A.size();
        vector<int> f;
        f.push_back(n-1);
        for(int i = n-2;i>=0;i--){
            for(int g:f){
                if(A[i]>=g-i){
                    f.push_back(i);
                    break;
                }
            }
        }
        return f[f.size()-1]==0;
    }
};


geek algorithm:

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        int maxs = 0;
        int n = A.size();
        for(int i = 0; i < n; i++){
            if(i>maxs){
                return false;
            }else{
                maxs = max(maxs,i+A[i]);
            }
        }
        return true;
    }
};
