/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/


class Solution {
public:
    /*
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
       long long start = 1;
        long long end = n;
       while(start<end){
            long long k = (start+end)>>1;
           if(SVNRepo::isBadVersion(k)){
               if(!(k-1) || !SVNRepo::isBadVersion(k-1)){
                   return k;
               }else{
                   end = k-1;
               }
           }else{
               if(SVNRepo::isBadVersion(k+1)){
                   return k+1;
               }else{
                   start = k+1;
               }
           }
       }
       return start;
    }

};
