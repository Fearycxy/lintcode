class Solution {
public:
    /**
     * @param color: the given color
     * @return: a 7 character color that is most similar to the given color
     */
    string similarRGB(string &color) {
        // Write your code here
        string an = "#";
        for(int i = 1;i<=3;i++){
            cout <<endl;
            char a = color[i*2-1];int f = cal(a);
            int y =f*16 + cal(color[i*2]) ;
            int t1 = abs(f*16 +f-y);
            int t2 = abs((f+1)*16 + f+1-y);
            int t3 =abs((f-1)*16 + f-1 - y);
            y = min(t1,min(t2,t3));
            char b = a;
            if(y==t2){
                 if(a == '9') b =  'A';
                 else b =  a+1;
            }else if(y==t3){
                 if(a=='A') b = '9';
                 else b = a-1;
            }
            an +=b;an+=b;
            cout << an <<endl;
        }
        return an;
    }
    
    inline int cal(char c){
        if(c>='a' && c <='f') return c-'a'+10;
        if(c >='A' && c<= 'F') return c-'A'+10;
        return c - '0';
    }
 
};
