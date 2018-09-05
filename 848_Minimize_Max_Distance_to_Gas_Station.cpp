//version 1 TLE!!!!
class Solution {
public:
    /**
     * @param stations: an integer array
     * @param k: an integer
     * @return: the smallest possible value of D
     */

    double minmaxGasDist(vector<int> stations, int k) {
        // Write your code here
        priority_queue<pair<double, int>> que;
        for (int i = 1; i < stations.size(); i++) que.push(make_pair((double) (stations[i] - stations[i - 1]), 1));
        while (k) {
            auto node = que.top();
            int l = node.second;
            k += l - 1;
            double top = node.first * l;
            que.pop();
            int y = static_cast<int>(top / que.top().first);
            if (y >= k + 1)return top / (k + 1);
            que.push({top / (y + 1), y + 1});
            k -= y;
        }
        return que.top().first;
    }
};


//version2:
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double left = 0, right = 1e8;
        while (right - left > 1e-6) {
            double mid = left + (right - left) / 2;
            int cnt = 0, n = stations.size();
            for (int i = 0; i < n - 1; ++i) {
                cnt += (stations[i + 1] - stations[i]) / mid;
            }
            if (cnt <= K) right = mid;
            else left = mid;
        }
        return left;
    }
};
