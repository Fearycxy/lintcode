class Solution {
public:
    
     double myPow(double x, int n) {
        // write your code here
        cout << x <<", "<<n<<endl;
        if(n==0) return 1;
        double an = myPow(x,n/2);
        an *=an;
        if(n%2==0) return an;
        return an * (n>0?x:1/x);
    }

};
