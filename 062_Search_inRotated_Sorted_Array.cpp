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
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        num = A;
        int n = A.size();
        this->target = target;
        if(n < 2){
            return n && A[0] == target? 0:-1;
        }
        if(A[0]<A[n-1]){
            return find(0,n-1);
        }else{
            int mid;
            int start = 0;
            int end = n-1;
            cout <<"end"<<end<<endl;
            while(start<end-1){
                mid = (start+end)/2;
                cout << start<<endl;
                cout <<end <<endl;
                cout << "mid: "<<mid<<end;
                if(num[mid] < num[mid-1]){
                    break;
                }else if(num[mid]<A[n-1]){
                    end = mid;
                }else {
                    start = mid;
                }
            }
            cout << "mid"<<mid<<end;
            int f = find(0,mid-1);
            if(f != -1){
                return f;
            }
            f = find(mid,n-1);
            return f;
            
        }
    }
};
