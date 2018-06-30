
class Solution {
public:
    /**
     * @param L: A positive integer
     * @param R: A positive integer
     * @return: the number of interesting subranges of [L, R]
     */
    // Follow the java implementation, we still use prefix sum of palindrome counts.
    int PalindromicRanges(int L, int R) {
        if (R < L) {
            return 0;
        }
        if (R == L) {
            return 1;
        }
        vector<int> dp(R-L+2); 
        for (int i=L; i<=R; ++i) {
            dp[i-L+1] = dp[i-L]; 
            if (isPal(i)) {
                ++dp[i-L+1];
            }
        }
        // 太簡單懶得寫了
        int count = 0;
        int len = dp.size();
        for (int i=1;i<len;++i) {
            for (int j=i-1;j>=0;--j) {
                if ((dp[i] - dp[j]) % 2 == 0) {
                    ++count;
                }
            }
        }
        return count;
    }
    
    bool isPal(int v) {
        int rev = 0;
        int temp = v;
        while (temp != 0) {
            rev = rev * 10;
            rev += temp % 10;
            temp = temp / 10;
        }
        return v == rev;
    }
};
