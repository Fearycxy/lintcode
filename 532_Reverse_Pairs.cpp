//1 TLE不理解呀 明明 也是n*log n  why 我的不行
class Solution {
public:
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        // write your code here
        if(A.empty()) return 0;
        multiset<int> mul;
        mul.insert(A[0]);
        long long ans = 0,n = A.size();
        for(int i=1;i<n;i++){
            ans+= distance(upper_bound(mul.begin(),mul.end(),A[i]),mul.end());
            mul.insert(A[i]);
        }
        return ans;
    }
};

//2 merge version
class Solution {
public:

    int *tem;
    /**
     * @param A: an array
     * @return: total of reverse pairs
     */
    long long reversePairs(vector<int> &A) {
        // write your code here
        if(A.empty()) return 0;
        tem = new int[A.size()];
        return merge(A,0,A.size()-1);
    }
    
    long long merge(vector<int> &A,int l ,int r){
        if(l==r){
            tem[l] = A[l];
            return 0ll;
        }
        long long re = 0,m = (l+r)>>1;
        re = merge(A,l,m)+ merge(A,m+1,r);
        //todo 
        int k =m,y = r,t = r;
        while(k>=l && y>=m+1){
            tem[t--] = max(A[y],A[k]);
            if(A[y]<A[k]) {
                re+= y-m;
                k--;
            }else{
                y--;
            }
        }
        while(y>=m+1) tem[t--] = A[y--];
        while(k>=l) tem[t--] = A[k--];
        for(int i=l;i<=r;i++) A[i]=tem[i];
        return re;
    }
};
