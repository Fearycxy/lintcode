// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    /**
     * @param n an integer
     * @return the number you guess
     */
    int guessNumber(int n) {
        // Write your code here
        long long left = 1, right = n;
        while(true){
            long long mid =(left +right)>>1;
            switch(guess(mid)){
                case 0:
                    return mid;
                case -1:
                    right = mid - 1;
                    break;
                case 1:
                    left = mid +1;;
            }
        }
    }
};
