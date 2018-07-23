class Solution {
public:
    /**
     * @param arr: the array
     * @return: the value 
     */
    long long findTheSumOfTheArray(vector<int> &arr) {
        // Write your code here
        const int mole = 1000000007;
        int an=0,n=arr.size();
        for(int i=0;i<n;i++)
	    an = (an +((arr[i]*(i+1)%mole)*(n-i))%mole)%mole;
        return an;
    }
