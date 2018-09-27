//http://www.cnblogs.com/grandyang/p/6620351.html
class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stol(n);
        for (int i = log(num + 1) / log(2); i >= 2; --i) {
            long long left = 2, right = pow(num, 1.0 / (i - 1)) + 1;
            while (left < right) {
                long long mid = left + (right - left) / 2, sum = 0;
                for (int j = 0; j < i; ++j) {
                    sum = sum * mid + 1;
                }
                if (sum == num) return to_string(mid);
                else if (sum < num) left = mid + 1;
                else right = mid;
            }
        }
        return to_string(num - 1);
    }
};

//https://leetcode.com/problems/smallest-good-base/discuss/96587/Python-solution-with-detailed-mathematical-explanation-and-derivation
//https://leetcode.com/problems/smallest-good-base/discuss/96597/5-liner-3ms-really-tight-search-bounds-with-time-complexity-analysis-ologn2-detailed-explanation
class Solution {
public:
    int64_t N; // =stoll(n)

    string smallestGoodBase(string n) {
        for (int64_t k, d=log2((N=stoll(n))+1); d>1;) if (k = root(d--)) return to_string(k);
    }

    int64_t f(int64_t k, int64_t d) { // f(k,d) = sum k^i - N
        for (int64_t i=0, p=1, sum=1; i<d; sum += p*=k) if (++i == d) return sum-N;
    }

    int64_t root(int64_t d) { // binary search root for f(*,d) in range [N^1/d, N^1/(d-1)]
        int64_t k;
        return d>2? f(k = pow(N,1./(d-1)), d)? 0 : k : N-1;
    }
};
/*Key Observation: if N in base k >= 2 has all digits as 1's, that means n has representation

        n = Σp=0:d-1 kp,
where d is the number of digits in base k. So the problem is equivalent to

find smallest k >= 2 such that function f(k,d) := Σp=0:d-1 kp - N = 0 for some integer d.
As many fellow coders have posted the popular binary search solution for root of f(*, d) with some fixed d, but I think the search bound for d and k should be tightened as much as possible to speed up the algorithm.

Range of d: Note that f(k,d) is strictly increasing in k, which means f(*,d) has most one root for a fixed d.
Note that f can be rewritten as

        f(k,d) = (kd-1)/(k-1)-N ≥ f(2,d) = 2d-1-N,
so we must have d ≤ log2(N+1) to be able to have a root for f(*,d).

Range of k: for a fixed d, we have

f(k,d) = (kd-1)/(k-1)-N < kd-N,
        so we must have the root k > N1/d.
We also have

        f(k,d) = Σp=0:d-1 kp - N > kd-1-N,
so we must have the root k < N1/(d-1).

Summary: we loop d only in range [2, log2(N+1)] reversely, and for each d, we binary search root for f(*,d) only in range [N1/d, N1/(d-1)].

int64_t N; // =stoll(n)

string smallestGoodBase(string n) {
    for (int64_t k, d=log2((N=stoll(n))+1); d>1;) if (k = root(d--)) return to_string(k);
}

int64_t f(int64_t k, int64_t d) { // f(k,d) = sum k^i - N
    for (int64_t i=0, p=1, sum=1; i<d; sum += p*=k) if (++i == d) return sum-N;
}

int64_t root(int64_t d) { // binary search root for f(*,d) in range [N^1/d, N^1/(d-1)]
    int64_t m, v, L = pow(N, 1./d), R = pow(N, 1./(d-1));
    for (; L <= R; v<0? L = m+1 : R = m-1) if (!(v = f(m=(L+R)/2,d))) return m;
    return d>2? 0 : N-1;
}
Time Complexity:

The loop in smallestGoodBase has length log N.
Apparently, function f(k,d) has O(d) complexity.
In binary search root, we have O(d*log(R-L)) = O(d*log R) = O(d*log N1/(d-1)) = O(log N).
So the overall time complexity is O(log N)2. (N = stoll(n))

Improvement for Function root:
Actually, as @StefanPochmann pointed out in this post with binomial theorem, only int64_t k = pow(N, 1./(d-1)) could be the candidate for the root of f(*,d). So method root can be simplified as following:

int64_t root(int64_t d) { // only N^1/(d-1) could be root for f(*,d)
    int64_t k;
    return d>2? f(k = pow(N,1./(d-1)), d)? 0 : k : N-1;
}
The overall time complexity still stands as O((log N)^2).*/
