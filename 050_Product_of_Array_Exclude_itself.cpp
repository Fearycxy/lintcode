class Solution {
public:
    /*
     * @param nums: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
    vector<long long> B;
    int len = nums.size();
    long long f[len + 1];

    f[len] = 1;
    for (int i = len - 1; i >= 0; --i) {
        f[i] = f[i + 1] * nums[i];
        //cout << "f[" << i << "] = f[" << i + 1 << "] * nums[" << i << "]" << endl;
        //cout << f[i] << " = " << f[i + 1] << " * " << nums[i] << endl;
    }
    long long tmp = 1;
    for (int i = 0; i < len; ++i) {
        //cout << f[i + 1] << endl;
        B.push_back(tmp * f[i + 1]);
//        cout << tmp * f[i + 1]<<endl;
        tmp *= nums[i];
    }
    return B;
}
};
