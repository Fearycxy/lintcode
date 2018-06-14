//solution1 @deprecated
class Solution {
public:
struct Cmp{
    const int y;
    Cmp(int l):y(l){}
    bool operator()(int i1,int i2)const{
        if(abs(y-i1)==abs(y-i2)) return i1<i2;
        return abs(y-i1) <abs(y-i2) ;
    }
};
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        // write your code here
        sort(A.begin(),A.end(),Cmp(target));
        vector<int> re;
        for(int i=0;i<k;i++){
            re.push_back(A[i]);
        }
        return re;
    }
};

//solution2 metoo hhhh 也是我自己的比网上那些快很多
class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        // write your code here
        vector<int> re;
        if(!k) return re;
        auto it = lower_bound(A.begin(),A.end(),target),lt= it;
        while(lt!=A.begin() && it != A.end()){
            if(target-*(lt-1)<=*it-target){
                re.push_back(*(--lt));
            }else{
                re.push_back(*it++);
            }
             if(re.size()==k) return re;
        }
        k -= re.size();
        if(it == A.end()) {
            int i =0;
            while(lt--!=A.begin() && i++<k) re.push_back(*lt);
        }else if(lt == A.begin()){
            re.insert(re.end(),it,A.end()-it>k?it+k:A.end());
        } 
         return re;
    }
    
};
