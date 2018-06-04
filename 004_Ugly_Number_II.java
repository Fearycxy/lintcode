public class Solution {
    /*
     * @param n: An integer
     * @return: the nth prime number as description.
     */
      List<Integer> l = new LinkedList();
    public int nthUglyNumber(int n) {
        // write your code here
        int re = 1;
        
        l.add(re);
        for(int i = 1;i < n;i++){
          int two = getMinNext(i-1,2);
          int three = getMinNext(i-1,3);
          int five = getMinNext(i-1,5);
          re = Math.min(two,five);
          re = Math.min(three,re);
          l.add(re);
        }
        return l.get(l.size()-1);
    }
    
    public int getMinNext(int i , int base){
        while(i>0 && l.get(i) % base >0){
            i--;
        }
        if(i == 0){
            return base;
        }else{
           return l.get(l.indexOf(l.get(i) / base)+1)*base ; 
        }
    }
  
}
