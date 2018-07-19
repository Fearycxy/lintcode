class Solution {
public:
    /**
     * @param N: a integer
     * @return: return a integer
     */
    int numTilings(int N) {
        // write your code here
        const int MOLE = 1e9+7;
        int a[4] = {1,2,5,0};
        if(N<=3) return a[N-1];
        for(int i =3;i<N;i++){
            a[3] = (a[2] *2 %MOLE + a[0]) %MOLE;
            for(int j = 0;j<=2;j++) a[j] = a[j+1];
        }
        return a[3]%MOLE;
    }
};
