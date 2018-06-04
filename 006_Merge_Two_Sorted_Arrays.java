public class Solution {
    /*
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    public int[] mergeSortedArray(int[] A, int[] B) {
        // write your code here
        int la = A.length;
        int lb = B.length;
        int l = la + lb;
        int[] re = new int[l];
        int i = 0;
        int ia = 0;
        int ib = 0;
        int sa =0;
        int sb = 0;
        while(i< l){
            if(ia < la){
                sa =  A[ia];
            }else{
                break;
            }
            if(ib<lb){
                sb = B[ib];
            }else{
                break;
            }
            int t = Math.min(sa,sb);
            if(t== sa){
                re[i] = sa;
                ia++;
            }else{
                re[i] = sb;
                ib++;
            }
            i++;
        }
        while(ib<lb){
            re[i] = B[ib];
            i++;
            ib++;
        }
       while(ia<la){
            re[i] = A[ia];
            i++;
            ia++;
        }
        return re;
        
    }
}
